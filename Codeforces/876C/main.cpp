#include <iostream>
#include <cstring>

using namespace std;

struct Books
{
   char  tieude[50];
   char  tacgia[50];
   char  chude[100];
   int   book_id;
};

int main( )
{
   struct Books QuyenSach1;        // Declare QuyenSach1 of type Book
   struct Books QuyenSach2;        // Declare QuyenSach2 of type Book

   // chi tiet ve quyen sach thu nhat
   strcpy( QuyenSach1.tieude, "Ngon ngu Lap trinh C++");
   strcpy( QuyenSach1.tacgia, "Pham Van At");
   strcpy( QuyenSach1.chude, "Lap trinh");
   QuyenSach1.book_id = 1225;

   // chi tiet ve quyen sach thu hai
   strcpy( QuyenSach2.tieude, "Toi thay hoa vang tren co xanh");
   strcpy( QuyenSach2.tacgia, "Nguyen Nhat Anh");
   strcpy( QuyenSach2.chude, "Van hoc");
   QuyenSach2.book_id = 3214;

   // in thong tin ve QuyenSach1
   cout << "Tieu de cua Quyen sach thu nhat la: " << QuyenSach1.tieude <<endl;
   cout << "Tac gia cua Quyen sach thu nhat la: " << QuyenSach1.tacgia <<endl;
   cout << "Chu de cua Quyen sach thu nhat la: " << QuyenSach1.chude <<endl;
   cout << "ID cua Quyen sach thu nhat la: " << QuyenSach1.book_id <<endl;

   cout << "\n\n===================================================================\n\n" <<endl;

   // in thong tin ve QuyenSach2
   cout << "Tieu de cua Quyen sach thu hai la: " << QuyenSach2.tieude <<endl;
   cout << "Tac gia cua Quyen sach thu hai la: " << QuyenSach2.tacgia <<endl;
   cout << "Chu de cua Quyen sach thu hai la: " << QuyenSach2.chude <<endl;
   cout << "ID cua Quyen sach thu hai la: " << QuyenSach2.book_id <<endl;

   return 0;
}
