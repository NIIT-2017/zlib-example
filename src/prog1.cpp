#include <zlib.h>
#include <memory.h>
#include <stdio.h>
 
#define SRC_SIZE 512
#define DST_SIZE 512
 
int main()
{
    // Входной буфер размером SRC_SIZE
    unsigned char source[SRC_SIZE];
    // Тут мы будем хранить размер входного буфера 
    // (переменная просто для наглядности)
    const unsigned long sourceLen = SRC_SIZE;
    // Выходной буфер
    unsigned char dest[DST_SIZE];
    // Размер выходного буфера
    unsigned long destLen = DST_SIZE;
 
    // Будем сжимать буфер забитый нулями
    memset(source, 0, SRC_SIZE * sizeof(source[0]));
 
    if (Z_OK == compress(dest, &destLen, source, sourceLen))
    {
      // Все успешно
        printf("Compress ratio: %.2f\n", destLen/(float) sourceLen);
    }
    else
    {
     // Тут можете разобрать код ошибки и вывести более подробную информацию
        printf("Compress failed\n");
    }
 
    return 0;
}
