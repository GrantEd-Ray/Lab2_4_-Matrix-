#include <iostream>

template<typename T, unsigned int N, unsigned int M>
class Matrix
{
    T m_matrix[N][M];
public:
    Matrix(T Nums[N][M])
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                m_matrix[i][j] = Nums[i][j];
    }

    Matrix(const Matrix& other)
    {
        
    }

    double determinant()
    {
        if (N == 2 && M == 2)
        {

        }
        else if (N == 3 && M == 3)
        {

        }
    }
};

using Matrix22i = Matrix<int, 2, 2>;
using Vector2i = Matrix<int, 2, 1>;

int main() {
    Matrix22i M;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
