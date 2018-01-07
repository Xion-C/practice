#include <stdio.h>
#include <stdlib.h>

#include "mat.h"

int main()
{
    {
        Mat<float> c(5, 5);
        c.init(1.1f);
        c.print();
        Mat<float> d(c);
        d = d * 2.2f;
        //10.10f * c;
        //Mat<float> e = c + d;
        //Mat<float> f = d - c;
        //c = d*c;
        //c.print();
        //d.print();

        //int a1[] = { 1,2,3 };
        //int a2[] = { 4,5,6 };
        //Mat<int> m1(a1, 1, 3);
        //Mat<int> m2(a2, 3, 1);
        //m1.print();
        //m2.print();
        //Mat<int> m3(m1*m2);
        //Mat<int> m4(m2*m1);
        //m3.print();
        //m4.print();
        //Mat<int> m1t(m1.transpose());
        //Mat<int> m2t(m2.transpose());
        //m1t.print();

        //Mat<float> empty;
        //empty.print();

        //Mat<int> size1(2, 3);
        //size1.init(3);
        //Mat<int> size2(3, 2);
        //size2.init(5);
        //size1 + size2;

        //m4.print();
        //Mat<int> sub1 = m4.submat(0, 2, 1, 2);
        //sub1.print();

        //Mat<float> mload;
        //mload.load("dat", 20, 4);
        //mload.print();
    
        //Mat<int> t1(10, 10);
        //t1.init(12);
        //t1.print();
        //std::cout << t1.at(3, 3) << std::endl;
        //std::cout << t1.ptr() << std::endl;

        //for (int i = 0; i < 1; i++) {
        //    std::cout << "this is " << i << std::endl;
        //    for (int j = 0; j < 2; j++) {
        //        std::cout << i << " - " << j << std::endl;
        //        Mat<int> mal(5, 5);
        //    }
        //}
    }
    
    system("pause");
    _CrtDumpMemoryLeaks();

    return 0;
}
