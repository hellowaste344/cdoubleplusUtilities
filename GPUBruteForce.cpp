#include <iostream>
#include <chrono>
#include <string>
#include <fstream>
#include <vector>
#include <cuda.h>
using namespace std;
using namespace std::chrono;
__global__ void gpuBruteForce(char* target, int targetLen, char* chars, int charsLen, bool* found, char* result) {
	long idx = blockIdx.x * blockDim.x + threadIdx.x;
	long totalCombinations = 1;
	for (int i = 0; i < targetLen; i++) {
		totalCombinations *= charsLen;
	}
	if (idx >= totalCombinations || *found) return;
	string attempt(targetLen, chars[0]);
	long tempIdx = idx;
	for (int i = targetLen - 1; i >= 0; i--) {
		attempt[i] = chars[tempIdx % charsLen];
		tempIdx /= charsLen;
	}
	if (attempt == string(target, targetLen)) {
		*found = true;
		for (int i = 0; i < targetLen; i++) {
			result[i] = attempt[i];
		}
	}
}
//
class GPUBruteForce {
	public:
	static void X(const string& target) {
		string chars =
			"abcdefghijklmnopqrstuvwxyz"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"0123456789"
			"!@#$%^&*()-_=+[]{};:'\",.<>/?\\|`~";
		int length = target.length();
		int charsLen = chars.size();
		long totalCombinations = 1;
		for (int i = 0; i < length; i++) {
			totalCombinations *= charsLen;
		}
		char *d_target, *d_chars, *d_result;
		bool *d_found, h_found = false;
		char h_result[100];
		cudaMalloc(&d_target, length);
		cudaMalloc(&d_chars, charsLen);
		cudaMalloc(&d_found, sizeof(bool));
		cudaMalloc(&d_result, length);
		cudaMemcpy(d_target, target.c_str(), length, cudaMemcpyHostToDevice);
		cudaMemcpy(d_chars, chars.c_str(), charsLen, cudaMemcpyHostToDevice);
		cudaMemcpy(d_found, &h_found, sizeof(bool), cudaMemcpyHostToDevice);
		int threadsPerBlock = 256;
		int blocks = (totalCombinations + threadsPerBlock - 1) / threadsPerBlock;
		gpuBruteForce<<<blocks, threadsPerBlock>>>(d_target, length, d_chars, charsLen, d_found, d_result);
		cudaDeviceSynchronize();
		cudaMemcpy(&h_found, d_found, sizeof(bool), cudaMemcpyDeviceToHost);
		if (h_found) {
			cudaMemcpy(h_result, d_result, length, cudaMemcpyDeviceToHost);
			cout << "Found the password: " << string(h_result, length) << "\n";
		} else {
			cout << "Password not found.\n";
		}
		cudaFree(d_target);
		cudaFree(d_chars);
		cudaFree(d_found);
		cudaFree(d_result);
	}
};
//
int main() {
	string line;
	ifstream infile("Password.text");
	while (getline(infile, line)) {
		auto start = high_resolution_clock::now();
		GPUBruteForce::X(line);
		auto end = high_resolution_clock::now();
		auto duration = duration_cast<seconds>(end - start).count();
		cout << "Time taken: " << duration.count() << " seconds\n";
	}
	return 0;
}
