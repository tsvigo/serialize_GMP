// #include <QCoreApplication>

// int main(int argc, char *argv[])
// {
//     QCoreApplication a(argc, argv);

//     return a.exec();
// }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <cstdio>
#include <gmpxx.h>
#include <iostream>
#include <cassert>

int main ()
{
    mpq_class original("1731181/1762217");

    original *= original; original *= original; original *= original;
    original *= original; original *= original; original *= original; // make it a little more interesting...

    std::cout << original << "\n";

    {
        FILE* output = fopen("/home/viktor/my_projects_qt_2/serialize_GMP/serialized.bin", "wb");
        mpz_out_raw(output, original.get_num_mpz_t());
        mpz_out_raw(output, original.get_den_mpz_t());
        fclose(output);
    }

    mpq_class restored;
    {
        FILE* input = fopen("/home/viktor/my_projects_qt_2/serialize_GMP/serialized.bin", "rb");
        mpz_inp_raw(restored.get_num_mpz_t(), input);
        mpz_inp_raw(restored.get_den_mpz_t(), input);
        fclose(input);
    }
std::cout << restored << "\n";
    assert(restored == original); // проверка
}
