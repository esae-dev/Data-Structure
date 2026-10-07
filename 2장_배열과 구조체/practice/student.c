//1. struct 이름만
struct Student {
    int id;
    char name[100];
    double score;
};
struct Student a;

//2. typedef 이름만
typedef struct {
    int id;
    char name[100];
    double score;
} Student;

Student a;

// 3. 둘 다
typedef struct Student {
    int id;
    char name[100];
    double score;
} Student;

struct Student a;
Student b; //결국 얘도 struct Student임