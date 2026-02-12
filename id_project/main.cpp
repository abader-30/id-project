#include <iostream>
#include <string>
#include<algorithm>
#include <cctype>
using namespace std;
string id;

// gender check
void gender(string id )
{
 string gendersub = id.substr
 (13, 1);
 int genderrr = stoi(gendersub);
 if (genderrr % 2 == 0) {
   gendersub = "FEMALE";
 }
 else {
  gendersub = "MALE";
 }
 cout << gendersub;
}
//id_long check
bool check_valid(string id)
{

    if (id.size() != 14) {
        cout << "*SORRY!! this number is unvalid please try again...*\n\n";
        return false;
    }
        // بتخلي اليوزر ميقدرش يكتب حروف
    for (int i = 0; i < id.size(); i++) {
    if (!isdigit(id[i])) {
        cout << "*SORRY!! this number is unvalid please try again...*\n\n";
        return false;
    }
}

    int g = stoi(id.substr(7, 2));
    int c = stoi(id.substr(0, 1));
    int m = stoi(id.substr(3, 2));
    int d = stoi(id.substr(5, 2));
    int y = stoi(id.substr(1, 2));
    int currentYear = 2026;
    int currentMonth = 2;
    int currentDay = 14;

    if (c == 2) y = 1900 + y;
    else if (c == 3) y = 2000 + y;

     /*الحالة دي لو الشخص لسة متولدش اصلا*/

/* cent(c) & months(m) & days(d) & g0v_code(g) check*/
    if ((c != 2 && c != 3) || (m < 1 || m > 12) || ( d<1 ||d > 31) ||
        !((g >= 1 && g <= 4) || (g >= 11 && g <= 19) || (g >= 21 && g <= 29) || (g >= 31 && g <= 35)||(g==25)||(g==88))) {
            /* ال88 دي يعني الشخص دة اتولد برة مصر و ضيفتها تحت انه اتولد برة عشان مكنتوش عاملينها انتوا*/
        cout << "*SORRY!! this number is unvalid please try again...*\n\n";
        return false;
    }
    // بمنع ان اليوزر يكتب سنه مستقبليه
if (y > currentYear ||
   (y == currentYear && m > currentMonth) ||
   (y == currentYear && m == currentMonth && d > currentDay))
{
    cout << "*SORRY!! this number is invalid (future date)*\n\n";
    return false;
}

/*the following two if conditions for to check the leap year
(السنه الكبيسة)*/
 if (m == 2) {
    if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0)) {
        // سنة كبيسة → فبراير فيه 29 يوم
        if (d > 29) {
            cout << "*SORRY!! this number is unvalid please try again...*\n\n";
            return false;
        }
    } else {
        // سنة عادية → فبراير فيه 28 يوم
        if (d > 28) {
            cout << "*SORRY!! this number is unvalid please try again...*\n\n";
            return false;
        }
    }
}
 /*يرجالة انا ضيفت الشروط بتاعت السنة الكبيسة و شرحتها*/
 /* الشرط دة عشان الشهور اللي مفيهاش 31 يوم*/
 if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) {
  cout << "*SORRY!! this number is unvalid please try again...*\n\n";
        return false ;
 }

 return true ;
}

/*كريم احنا معرفين السنة فوق بy عشان و انت بتعمل الage متعرفهاش بحاجة مختلفة*/

void governorate(string id)
{
 int gov[28] = {1,2,3,4,11,12,13,14,15,16,17,18,19,21,22,23,24,25,26,27,28,29,31,32,33,34,35,88};
 string gov_name[28] = {
  "Cairo", "Alexandria", "Port Said", "Suez",
  "Damietta", "Dakahlia", "Sharqia", "Qalyubia",
  "Kafr El-Sheikh", "Gharbia", "Monufia", "Beheira",
  "Ismailia", "Giza", "Beni Suef", "Fayoum",
  "Minya", "Assiut", "Sohag", "Qena",
  "Aswan", "Luxor", "Red Sea", "New Valley",
  "Matrouh", "North Sinai", "South Sinai","Born outside Egypt" };

/*انا هنا علمت اتنين اراي عشان لو كود المحافظة اللي اتدخل موجود الاراي التاني يطلع الاسم المقابل ليه*/

 int g = stoi(id.substr(7, 2));
 for (int i = 0; i < 28; i++)
 {
  if (gov[i] == g)
  {
   cout << gov_name[i];
  }
 }
}
// exact age calculation
void age(string id)
{
 int d = stoi(id.substr(5, 2));
 int thisday = 14; /* assuming run befor day 14th this month*/
 int age=0;
 int thismonth = 2; /*current month*/
 int monthbirth = stoi(id.substr(3, 2));
 int thisyear = 2026; /* current year*/
 int y = stoi(id.substr(1, 2));
 int cent;
 int c = stoi(id.substr(0, 1));
 cent = c;

 if (cent == 3) {
  age = thisyear - (2000 + y);
 }
 else if (cent == 2) {
  age = thisyear - (1900 + y);
 }
  /* ضيفت دي انا ,دي بتحسب العمر بالظبط عشان لو يوم و شهر الميلاد لسة مجاش */
 if  (monthbirth > thismonth || (monthbirth == thismonth && d > thisday)) {
  age = age - 1;
 }
 cout << age;
}
int main()
{
 cout << "=============================================" << endl;
 cout << "  ========== NATIONAL ID ANALYSIS==========  " << endl;
 cout << "=============================================" << "\n\n";
 cout << "---------------------------------------------"<<"\n";
 do{
       cout << "ENTER YOUR NATIONAL ID   :";
 cin >> id;

 } while(!check_valid(id));
 int m = stoi(id.substr(3, 2));
 int d = stoi(id.substr(5, 2));
 int c = stoi(id.substr(0, 1));
 int y = stoi(id.substr(1, 2));
 if (c == 2) y = 1900 + y;
 else if (c == 3) y = 2000 + y;

 // 3mlt do-while 3lshan asma7 ll user yda5al awel marra
// mn 8er ma yet7aqq shart "check valid"
// law el shart msh mt7aqq, yfdl el user ye3mel "c in" tani

 cout << "\n" << " BIRTH DATE        :" << y << "/" << m << "/" << d ;
 cout <<"\n\n" << " AGE               :";
 age(id);
 cout << "\n \n" << " GENDER            :";
 gender(id);
 cout << "\n \n" << " GOVERNORATE       :";
 governorate(id);
 cout << "\n\n" << " STATUS   :" << "VALID : ) \n";
 cout << "---------------------------------------------";
}
