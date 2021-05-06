typedef struct
{
    int day;
    int month;
    int year;
} date;
typedef struct
{
    char firstname[50];
    char lastname[50];
    date birthdate;
    char address[100];
    char email[100];
    char phonenumber[100];

} contact;
void load();
void add();
void printsorted();
void sort_by_name();
void sort_by_date();
void search();
void modify();
void delete();
void save();
void quit();
