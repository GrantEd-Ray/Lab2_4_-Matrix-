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

     const T& operator()(unsigned int i, unsigned int j) const
    {
        return m_matrix[i][j];
    }

     Matrix& operator+=(const Matrix& other)
     {
         for (int i = 0; i < N; i++)
             for (int j = 0; j < M; j++)
                 (*this).m_matrix[i][j] += other.m_matrix[i][j];
         return *this;
     }

     Matrix& operator+(const Matrix& other)
     {
         Matrix temp = *this;
         temp += other;
         return temp;
     }

     template<typename U, typename V>
     U& operator*=(const V& other)
     {
         if ((*this).get_row_size() == other.get_column_size() && (*this).get_column_size() == other.get_row_size())
         {
             ...
         }
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
        else if (N != M)
        {
            std::cout << "Determinant for this matrix does not exist!!!" << std::endl;
            return -1;
        }
    }

    template<typename T, unsigned int N, unsigned int M>
    friend std::ostream& operator<<(std::ostream& out, const Matrix<T, N, M>& mtr);

    template<typename T, unsigned int N, unsigned int M>
    friend std::istream& operator>>(std::istream& in, Matrix<T, N, M>& mtr);
};

template<typename T, unsigned int N, unsigned int M>
std::ostream& operator<<(std::ostream& out, const Matrix<T, N, M>& mtr)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            out << mtr(i, j) << " ";
        out << std::endl;
    }
    return out;
}

template<typename T, unsigned int N, unsigned int M>
std::istream& operator>>(std::istream& in, Matrix<T, N, M>& mtr)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            in >> mtr(i, j);
    }
    return in;
}

using Matrix33i = Matrix<int, 3, 3>;
using Matrix22i = Matrix<int, 2, 2>;
using Vector2i = Matrix<int, 2, 1>;

int main() {
    Matrix22i mrx;

    std::cin >> mrx;
    std::cout << mrx;

    std::cout << mrx.determinant() << std::endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
