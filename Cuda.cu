// kernel definition
__global__ void vecAdd(float* A, float* B, float* C)
{

}

int main(){
    // kernel invocation
    vecAdd<<<1,256>>>(A,B,C);
}
