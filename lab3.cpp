#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>

const int N = 5;




int main()
{

    int mas[N][N];
    int v[N];
    

    int dop[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mas[i][j] = 0;
            dop[i][j] = 0;
            v[i] = 0;
            
        }
    }
    std::string m;
    std::string line;
    int k = 0;
    int r = 0;
    std::ifstream in("in.txt");
    if (in.is_open())
    {
        while (!in.eof()) {
            while (getline(in, line))
            {
                m = line;
                for (int i = 0; i < m.length(); i++) {
                    if (m[i] != ' ') {
                        dop[k][r] = dop[k][r] * 10 + (int)m[i] - 48;
                    }
                    else {
                        r++;
                    }
                }
                k++;
                r = 0;
            }
        }

    }
    in.close();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dop[i][j] != 0) {
                mas[i][dop[i][j] - 1] = 1;

            }

        }
    }







    int dano = 1;
    int danotwo = dano;
    int komp = 1;



    while (1) {


        std::queue<int> ver;
        ver.push(dano - 1);




        while (!ver.empty()) {
            int n = ver.front();
            ver.pop();
            v[n] = 1;
            for (int i = 0; i < N; i++) {
                if (mas[n][i] == 1) {
                    if (v[i] == 0) {
                        v[i] = 2;

                        ver.push(i);
                    }


                }
            }
        }


        for (int i = 0; i < N; i++) {
            if (v[i] == 0) {
                dano = i + 1;

            }


        }


        for (int i = 0; i < N; i++) {
            if (v[i]> 0) {
                std::cout << i + 1 << " ";
                v[i] = -1;
            }
        }


        std::cout << std::endl;

        if (dano != danotwo) {
            komp++;
            danotwo = dano;

      
        }
        else {
            break;
        }

     

    }
    std::cout << std::endl;
    std::cout << komp;
}
