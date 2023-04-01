#include <iostream>

template<typename T, unsigned int N, unsigned int M>
class Matrix
{
    T m_matrix[N][M];
public:
    Matrix()
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                m_matrix[i][j] = 0;
    }

    Matrix(T Nums[N][M])
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                m_matrix[i][j] = Nums[i][j];
    }

    Matrix(const Matrix& other)
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                m_matrix[i][j] = other(i, j);
    }

    /*~Matrix()
    {
        delete m_matrix;
    }*/

    unsigned int get_column_size()
    {
        return N;
    }

    unsigned int get_row_size()
    {
        return M;
    }

    T& operator()(unsigned int i, unsigned int j)
    {
        return m_matrix[i][j];
    }

    T determinant()
    {
        if (N == 2 && M == 2)
        {
            return m_matrix[1][1] * m_matrix[0][0] - m_matrix[0][1] * m_matrix[1][0];
        }
        else if (N == 3 && M == 3)
        {
            T det;
            for (int i = 0; i < 3; i++)
                det += m_matrix[1][i] * m_matrix[2][(i+1) % 3] * m_matrix[3][(i+2) % 3] - m_matrix[1][i] * m_matrix[2][(i+2) % 3] * m_matrix[3][(i+1) % 3];
            return det;
        }
        else if (N == M)
    }

    friend std::ostream& operator<<(std::ostream& out, const Matrix& mtr);
    friend std::istream& operator>>(std::istream& in, const Matrix& mtr);
};

template<typename T, unsigned int N, unsigned int M>
std::ostream& operator<<(std::ostream& out, const Matrix<T, N, M>& mtr)
{
    for (int i = 0; i < mtr.get_column_size(); i++)
    {
        for (int j = 0; j < mtr.get_row_size(); j++)
            out << mtr(i, j) << " ";
        out << std::endl;
    }
    return out;
}

template<typename T, unsigned int N, unsigned int M>
std::istream& operator>>(std::istream& in, const Matrix<T, N, M>& mtr)
{
    for (int i = 0; i < mtr.get_column_size(); i++)
    {
        for (int j = 0; j < mtr.get_row_size(); j++)
            in >> mtr(i, j);
    }
    return in;
}


using Matrix22i = Matrix<int, 2, 2>;
using Vector2i = Matrix<int, 2, 1>;

int main() {
    Matrix22i mrx;

    std::cin >> mrx;
    std::cout << mrx;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
