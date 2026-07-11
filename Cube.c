#include <math.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
// gcc cube.c -lm -o cube

int k;
const float step = 0.025; // face sampling density

int main()
{
    float A = 0, B = 0;
    float zbuff[1760];
    char b[1760];

    // 6 faces: { face_normal(nx,ny,nz), u_tangent(ux,uy,uz), v_tangent(vx,vy,vz) }
    // face center = normal; u,v tangents span [-1,1] x [-1,1] across the face
    float faces[6][9] = {
        { 0,  0,  1,  1, 0, 0,  0, 1, 0},   // front  z=+1
        { 0,  0, -1, -1, 0, 0,  0, 1, 0},   // back   z=-1
        { 1,  0,  0,  0, 0,-1,  0, 1, 0},   // right  x=+1
        {-1,  0,  0,  0, 0, 1,  0, 1, 0},   // left   x=-1
        { 0,  1,  0,  1, 0, 0,  0, 0,-1},   // top    y=+1
        { 0, -1,  0,  1, 0, 0,  0, 0, 1},   // bottom y=-1
    };

    printf("\x1b[2J");

    for (;;)
    {
        memset(b, 32, 1760);
        memset(zbuff, 0, 7040);

        float sA = sin(A), cA = cos(A);
        float sB = sin(B), cB = cos(B);

        for (int f = 0; f < 6; f++)
        {
            float nx = faces[f][0], ny = faces[f][1], nz = faces[f][2];
            float ux = faces[f][3], uy = faces[f][4], uz = faces[f][5];
            float vx = faces[f][6], vy = faces[f][7], vz = faces[f][8];

            for (float u = -1.0f; u <= 1.0f; u += step)
            for (float v = -1.0f; v <= 1.0f; v += step)
            {
                // 3D point on cube surface — half-width 2, same scale as donut
                float px = 2*(nx + u*ux + v*vx);
                float py = 2*(ny + u*uy + v*vy);
                float pz = 2*(nz + u*uz + v*vz);

                // Rotate around X axis by A  (unchanged from donut)
                float py1 = cA*py - sA*pz;
                float pz1 = sA*py + cA*pz;

                // Rotate around Z axis by B  (unchanged from donut)
                float px2 = cB*px  - sB*py1;
                float py2 = sB*px  + cB*py1;
                float pz2 = pz1;

                // Perspective projection     (unchanged from donut)
                float D = 1.0f / (pz2 + 5);
                int x = 40 + (int)(30*D*px2);
                int y = 12 + (int)(15*D*py2);
                int o = x + 80*y;

                if (y > 0 && y < 22 && x > 0 && x < 80 && D > zbuff[o])
                {
                    zbuff[o] = D;

                    // Rotate the face normal the same way as the point
                    float rny1 = cA*ny - sA*nz;
                    float rnz1 = sA*ny + cA*nz;
                    float rnx2 = cB*nx  - sB*rny1;
                    float rny2 = sB*nx  + cB*rny1;

                    // Lambertian shading: dot normal with fixed light (0.577, 0.577, 0.577)
                    float lum = 0.577f*(rnx2 + rny2 + rnz1);
                    int N = (int)(8*lum);
                    if (N < 0) N = 0;
                    if (N > 11) N = 11;
                    b[o] = ".,-~:;=!*#$@"[N];
                }
            }
        }

        printf("\x1b[H");
        for (k = 0; k < 1761; k++)
            putchar(k % 80 ? b[k] : '\n');

        A += 0.04;
        B += 0.02;
        usleep(10000);
    }
}
