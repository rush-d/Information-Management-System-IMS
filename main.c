#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

enum branch {CSE, EE, ME};

struct course {
    char code[MAX];
    char name[MAX];
    int credits;
    int ninstructors;
    char **instructor_ids;
    int nstudents;
    char **student_rollnos;
};

struct student {
    char rollno[MAX];
    char name[MAX];
    enum branch branch;
    int semester;
    int ncourses;
    char **course_codes;
};

struct instructor {
    char id[MAX];
    char name[MAX];
    int ncourses;
    char **courses_codes;
};

void print_students();
void print_student(struct student s);
void print_instructors();
void print_instructor(struct instructor i);
void print_courses();
void print_course(struct course c);

void add_student(struct student s);
void add_instructor(struct instructor i);
void add_course(struct course c);

void adds_file();
void addi_file();
void addc_file();

void adds_file_d(char *z);
void addi_file_d(char *z);
void addc_file_d(char *z);

void mod_student(char *z);
void mod_instructor(char *z);
void mod_course(char *z);

void del_student(char *z);
void del_instructor(char *z);
void del_course(char *z);

void load_records();
void load_students();
void load_instructors();
void load_courses();

int string_checker(char *z);

struct course *courses;
struct student *students;
struct instructor *instructors;

FILE *fps;
FILE *fpc;
FILE *fpi;

char students_file[MAX] = "students.txt";
char courses_file[MAX] = "courses.txt";
char instructors_file[MAX] = "instructors.txt";

int ncourses = 0, nstudents = 0, ninstructors = 0, check =1;
char char_d[7]="default";
int int_d=1;

int main() {
    int m1,m2,m3,m4;
    char c1[10],c2[10];
while(1){
    nstudents=0;
    ninstructors=0;
    ncourses=0;
    load_records();
    printf("**----------------------------------------**\n");
    printf("**Welcome to INFORMATION MANAGEMENT SYSTEM**\n");
    printf("**________________________________________**\n\n");
    printf("Select from the following:-\n(Enter the number associated with it.)\n\n");
    printf("1.Student Options\n2.Instructor Options\n3.Course Options\n4.Exit\n\nEnter your choice: ");
    scanf("%d",&m1);
    switch(m1){
    default:
        printf("Wrong option.\nTry again.\n");
        break;
    case 1:
    	printf("\n**--------------------------**\n");
	printf("**Student Information Portal**\n");
    	printf("**__________________________**\n\n");
    	printf("Select from the folllowing:-\n(Enter the number associated with it.)\n\n");
        printf("1.Display Details of All Students\n2.Display Details of a specific Student\n3.Add a New Student\n4.Modify Student Details\n5.Delete Student\n\nEnter your choice: ");
        scanf("%d",&m2);
        switch(m2){
        default:
            printf("Wrong option.\nTry again.\n");
            fclose(fps);
            break;
        case 1:
            print_students();
	    printf("------------------------------------\n");
	    printf("Students' List Ends Here.\n\n");
            fclose(fps);
            break;
        case 2:
            printf("\nEnter roll number: ");
            scanf("%s",c1);
	    if(string_checker(c1)){
	    printf("\n");
            for(int i=0;i<nstudents;i++){
                if(strcmp(c1,students[i].rollno)==0){
                    m3=i;
                    break;
                }
            }
	    printf("\nStudent Roll Number %s Information\n",c1);
	    printf("----------------------------------------------\n");
            print_student(students[m3]);
	    printf("-----------------------------------\n");
	    printf("Student Roll number %s Infromation Ends Here.\n\n",c1);
	    }
	    else{
                 printf("\n**Student not found.**\n\n");
	        }
            fclose(fps);
            break;
        case 3:
            fclose(fps);
            printf("\n");
            adds_file();
            break;
        case 4:
            printf("\nEnter roll number: ");
            scanf("%s",c1);
            mod_student(c1);
            break;
        case 5:
            printf("\nEnter roll number: ");
            scanf("%s",c1);
            del_student(c1);
            break;
		}
            break;
    case 2:
	printf("\n**-----------------------------**\n");
   	printf("**Instructor Information Portal**\n");
    	printf("**_____________________________**\n\n");
    	printf("Select from the folllowing:-\n(Enter the number associated with it.)\n\n");
        printf("1.Display Details of All Instructors\n2.Display Details of a specific Instructor\n3.Add a New instructor\n4.Modify Instructor Details\n5.Delete Instructor\n\nEnter your choice: ");
        scanf("%d",&m2);
        switch(m2){
        default:
            printf("Wrong option.\nTry again.\n");
	    printf("------------------------------------\n");
	    printf("Instructors' List Ends Here.\n\n");
            fclose(fpi);
            break;
        case 1:
            print_instructors();
            fclose(fpi);
            break;
        case 2:
            printf("Enter instructor ID: ");
            scanf("%s",c2);
	    if(string_checker(c2)){
            for(int d=0;d<ninstructors;d++){
                if(strcmp(c2,instructors[d].id)==0){
                    m4=d;
                    break;
                }
            }
	    printf("\nInstructor ID %s Information\n",c2);
	    printf("--------------------------------------------\n");
            print_instructor(instructors[m4]);
	    printf("-----------------------------------\n");
	    printf("Instructor ID %s Infromation Ends Here.\n\n",c2);
	    }
	    else{
	         printf("\n**Instructor not found.**\n\n");
	        }
            fclose(fpi);
            break;
        case 3:
            fclose(fpi);
	    printf("\n");
            addi_file();
            break;
        case 4:
            printf("Enter Instructor ID: ");
            scanf("%s",c1);
            mod_instructor(c1);
            break;
        case 5:
            printf("Enter Instructor ID: ");
            scanf("%s",c1);
            del_instructor(c1);
            break;
            }
            break;
    case 3:
	printf("\n**-------------------------**\n");
        printf("**Course Information Portal**\n");
    	printf("**_________________________**\n\n");
    	printf("Select from the following:-\n(Enter the number associated with it.)\n\n");
        printf("1.Display Details of All Courses\n2.Display Details of a specific Course\n3.Add a New Course\n4.Modify Course Details\n5.Delete Course\n\nEnter your choice: ");
        scanf("%d",&m2);
        switch(m2){
        default:
            printf("Wrong option.\nTry again.\n");
            fclose(fpc);
            break;
        case 1:
            print_courses();
	    printf("------------------------------------\n");
	    printf("Courses' List Ends Here.\n\n");
            fclose(fpc);
            break;
        case 2:
            printf("Enter Course Code: ");
            scanf("%s",c2);
	    if(string_checker(c2)){
            for(int d=0;d<ncourses;d++){
                if(strcmp(c2,courses[d].code)==0){
                    m4=d;
                    break;
                }
            }
	    printf("\nCourse Code %s Information\n",c2);
	    printf("--------------------------------------\n");
            print_course(courses[m4]);
	    printf("-----------------------------------\n");
	    printf("Course Code %s Infromation Ends Here.\n\n",c2);
	    }
	    else{
	         printf("\n**Course Not Found.**\n\n");
	        }
	    fclose(fpc);
            break;
        case 3:
            fclose(fpc);
            addc_file();
            break;
        case 4:
            printf("Enter Course Code: ");
            scanf("%s",c1);
            mod_course(c1);
            break;
        case 5:
            printf("Enter Course Code: ");
            scanf("%s",c1);
            del_course(c1);
            break;
            }
	    break;

    case 4:
	printf("\n**Thanks for using this service.**\n\n");
	return 0;
	break;
    	}
    }
}

void add_student(struct student s) {
    students = realloc (students, (nstudents+1)*sizeof(struct student));
    students[nstudents] = s;
    nstudents++;
}

void add_instructor(struct instructor i) {
    instructors = realloc (instructors, (ninstructors+1)*sizeof(struct instructor));
    instructors[ninstructors] = i;
    ninstructors++;
}

void add_course(struct course c) {
    courses = realloc (courses, (ncourses+1)*sizeof(struct course));
    courses[ncourses] = c;
    ncourses++;
}

void print_students() {
    printf("\n***Students' details***\n-----------------------\n\n");
    for (int i=0; i<nstudents; i++) {
        print_student(students[i]);
    }
}

void print_instructors() {
    printf("\n***Instructors' details***\n--------------------------\n\n");
    for (int k=0; k<ninstructors; k++) {
        print_instructor(instructors[k]);
    }
}

void print_courses() {
    printf("\n***Courses' details***\n----------------------\n\n");
    for (int i=0; i<ncourses; i++) {
        print_course(courses[i]);
    }
}

void print_student(struct student s) {
    printf("Roll no.: %s\n", s.rollno);
    printf("Name: %s\n", s.name);
    printf("Branch: %d\n", s.branch);
    printf("Semester: %d\n", s.semester);
    printf("No. of courses: %d\n",s.ncourses);
    printf("List of courses:-\n");
    for (int i=0; i<s.ncourses; i++) {
        printf("Course Code [%d]: %s\n",i+1, s.course_codes[i]);
    }
    printf("\n\n");
}

void print_instructor(struct instructor i) {
    printf("ID: %s\n", i.id);
    printf("Name: %s\n", i.name);
    printf("No. of courses: %d\n",i.ncourses);
    printf("List of courses:-\n ");
    for (int h=0; h<i.ncourses; h++) {
        printf("Course Code [%d]: %s\n",h+1, i.courses_codes[h]);
    }
    printf("\n\n");
}

void print_course(struct course c) {
    printf("Code: %s\n", c.code);
    printf("Name: %s\n", c.name);
    printf("No.of credits: %d\n",c.credits);
    printf("No. of instructors: %d\n",c.ninstructors);
    printf("List of instructors:-\n");
    for (int h=0; h<c.ninstructors; h++) {
        printf("Instructor ID [%d]: %s\n",h+1, c.instructor_ids[h]);
    }
    printf("No. of students: %d\n",c.nstudents);
    for(int h=0;h<c.nstudents;h++){
        printf("Student Roll Number [%d]: %s\n",h+1, c.student_rollnos[h]);
    }
    printf("\n\n");
}

void load_records() {
     load_students();
     load_instructors();
     load_courses();
}

void load_students() {
    fps = fopen(students_file, "r");
    int nstudents;
    char buf[MAX];
    struct student s;
    fscanf(fps, "%d", &nstudents);
    for (int i=0; i<nstudents; i++) {
        fgets(buf, MAX, fps);
        fscanf(fps, "%s", s.rollno);
        fscanf(fps, " %[^\n]s", s.name);
        fscanf(fps, "%u", &s.branch);
        fscanf(fps, "%d", &s.semester);
        fscanf(fps, "%d", &s.ncourses);
        s.course_codes = malloc (s.ncourses * sizeof(char *));
        for (int j=0; j<s.ncourses; j++) {
            s.course_codes[j] = malloc (MAX * sizeof (char));
            fscanf(fps, "%s", s.course_codes[j]);
        }
        add_student(s);
    }
}

void load_instructors() {
    fpi = fopen(instructors_file, "r");
    int ninstructors;
    char buf[MAX];
    struct instructor i;
    fscanf(fpi, "%d", &ninstructors);
    for (int g=0; g<ninstructors; g++) {
        fgets(buf, MAX, fpi);
        fscanf(fpi, "%s", i.id);
        fscanf(fpi, " %[^\n]s", i.name);
        fscanf(fpi, "%d", &i.ncourses);
        i.courses_codes = malloc (i.ncourses * sizeof(char *));
        for (int f=0; f<i.ncourses; f++) {
            i.courses_codes[f] = malloc (MAX * sizeof (char));
            fscanf(fpi, "%s", i.courses_codes[f]);
        }
        add_instructor(i);
    }
}

void load_courses() {
    fpc = fopen(courses_file, "r");
    int ncourses;
    char buf[MAX];
    struct course c;
    fscanf(fpc, "%d", &ncourses);
    for (int g=0; g<ncourses; g++) {
        fgets(buf, MAX, fpc);
        fscanf(fpc, "%s", c.code);
        fscanf(fpc, " %[^\n]s", c.name);
        fscanf(fpc, "%d", &c.credits);
        fscanf(fpc, "%d", &c.ninstructors);
        c.instructor_ids = malloc (c.ninstructors * sizeof(char *));
        for (int f=0; f<c.ninstructors; f++) {
            c.instructor_ids[f] = malloc (MAX * sizeof (char));
            fscanf(fpc, "%s", c.instructor_ids[f]);
        }
        fscanf(fpc, "%d", &c.nstudents);
        c.student_rollnos = malloc (c.nstudents * sizeof(char *));
        for(int f=0; f<c.nstudents;f++){
            c.student_rollnos[f] = malloc (c.nstudents * sizeof(char*));
            fscanf(fpc, "%s", c.student_rollnos[f]);
        }
        add_course(c);
    }
}

void adds_file(){
    struct student s;
    char h1[20];
    printf("Enter roll number: ");
    scanf("%s",h1);
    if(string_checker(h1)){
        printf("\nStudent Roll Number already exists.\n");
    }
    else{
    strcpy(s.rollno,h1);
    printf("Enter name: ");
    scanf(" %[^\n]s",s.name);
    printf("Enter branch number code (CSE=0 or EE=1 or ME=2): ");
    scanf("%u",&s.branch);
    printf("Enter semester: ");
    scanf("%d",&s.semester);
    printf("Enter no. of courses: ");
    scanf("%d",&s.ncourses);
    s.course_codes = malloc (s.ncourses * sizeof(char *));
    printf("Enter the course codes:-\n");
    char v1[20];
    for(int i=0;i<s.ncourses;i++){
        printf("Course Code [%d]: ",i+1);
        scanf("%s",v1);
        if(string_checker(v1)){
        s.course_codes[i] = malloc (MAX * sizeof (char));
        strcpy(s.course_codes[i],v1);
        }
        else{
        addc_file_d(v1);
        s.course_codes[i] = malloc (MAX * sizeof (char));
        strcpy(s.course_codes[i],v1);
        }
    }
    add_student(s);
    fps=fopen(students_file,"w");
    fprintf(fps,"%d\n",nstudents);
        for(int h=0;h<nstudents;h++){
        fprintf(fps,"\n%s\n",students[h].rollno);
        fprintf(fps,"%s\n",students[h].name);
        fprintf(fps,"%u\n",students[h].branch);
        fprintf(fps,"%d\n",students[h].semester);
        fprintf(fps,"%d\n",students[h].ncourses);
        for(int j=0;j<students[h].ncourses;j++){
            fprintf(fps,"%s ",students[h].course_codes[j]);
        }
        putc('\n',fps);
        }
	printf("\n\n");
        fclose(fps);
	printf("Student Roll Number %s added.\n\n",h1);
}
}

void adds_file_d(char *z){
    struct student s;
    strcpy(s.rollno,z);
    strcpy(s.name,char_d);
    s.branch=int_d;
    s.semester=int_d;
    s.ncourses=int_d;
    s.course_codes = malloc (s.ncourses * sizeof(char *));
    for(int i=0;i<s.ncourses;i++){
        s.course_codes[i] = malloc (MAX * sizeof (char));
        strcpy(s.course_codes[i],char_d);
    }
    add_student(s);
    fps=fopen(students_file,"w");
    fprintf(fps,"%d\n",nstudents);
        for(int h=0;h<nstudents;h++){
        fprintf(fps,"\n%s\n",students[h].rollno);
        fprintf(fps,"%s\n",students[h].name);
        fprintf(fps,"%u\n",students[h].branch);
        fprintf(fps,"%d\n",students[h].semester);
        fprintf(fps,"%d\n",students[h].ncourses);
        for(int j=0;j<students[h].ncourses;j++){
            fprintf(fps,"%s ",students[h].course_codes[j]);
        }
        putc('\n',fps);
        }
	printf("\n\n");
        fclose(fps);
}

void addi_file(){
    struct instructor i;
    char h1[10];
    printf("Enter ID: ");
    scanf("%s",h1);
    if(string_checker(h1)){
        printf("\nInstructor ID already exists.\n\n");
    }
    else{
    strcpy(i.id,h1);
    printf("Enter name: ");
    scanf(" %[^\n]s",i.name);
    printf("Enter no. of courses: ");
    scanf("%d",&i.ncourses);
    i.courses_codes = malloc (i.ncourses * sizeof(char *));
    printf("Enter the course codes:-\n");
    char v1[20];
    for(int k=0;k<i.ncourses;k++){
        printf("Course [%d]: ",k+1);
        scanf("%s",v1);
        if(string_checker(v1)){
        i.courses_codes[k] = malloc (MAX * sizeof (char));
        strcpy(i.courses_codes[k],v1);
        }
        else{
        addc_file_d(v1);
        i.courses_codes[k] = malloc (MAX * sizeof (char));
        strcpy(i.courses_codes[k],v1);
        }
    }
    add_instructor(i);
    fpi=fopen(instructors_file,"w");
    fprintf(fpi,"%d\n",ninstructors);
        for(int h=0;h<ninstructors;h++){
        fprintf(fpi,"\n%s\n",instructors[h].id);
        fprintf(fpi,"%s\n",instructors[h].name);
        fprintf(fpi,"%d\n",instructors[h].ncourses);
        for(int j=0;j<instructors[h].ncourses;j++){
            fprintf(fpi,"%s ",instructors[h].courses_codes[j]);
        }
        putc('\n',fpi);
        }
	printf("\n\n");
        fclose(fpi);
	printf("\n**Instructor ID %s added.**\n\n",h1);
    }
}

void addi_file_d(char *z){
    struct instructor i;
    strcpy(i.id,z);
    strcpy(i.name,char_d);
    i.ncourses=int_d;
    i.courses_codes = malloc (i.ncourses * sizeof(char *));
    for(int k=0;k<i.ncourses;k++){
        i.courses_codes[k] = malloc (MAX * sizeof (char));
        strcpy(i.courses_codes[k],char_d);
    }
    add_instructor(i);
    fpi=fopen(instructors_file,"w");
    fprintf(fpi,"%d\n",ninstructors);
        for(int h=0;h<ninstructors;h++){
        fprintf(fpi,"\n%s\n",instructors[h].id);
        fprintf(fpi,"%s\n",instructors[h].name);
        fprintf(fpi,"%d\n",instructors[h].ncourses);
        for(int j=0;j<instructors[h].ncourses;j++){
            fprintf(fpi,"%s ",instructors[h].courses_codes[j]);
        }
        putc('\n',fpi);
        }
	printf("\n\n");
        fclose(fpi);
}

void addc_file(){
    struct course c;
    char h1[10];
    printf("Enter course code: ");
    scanf("%s",h1);
    if(string_checker(h1)){
        printf("\nCourse Code already exists.\n\n");
    }
    else{
    strcpy(c.code,h1);
    printf("Enter name: ");
    scanf(" %[^\n]s",c.name);
    printf("Enter no. of credits: ");
    scanf("%d",&c.credits);
    printf("Enter no. of instructors: ");
    scanf("%d",&c.ninstructors);
    c.instructor_ids = malloc (c.ninstructors * sizeof(char *));
    printf("Enter the instructor IDs:-\n");
    char v1[20];
    for(int k=0;k<c.ninstructors;k++){
        printf("Instructor ID [%d]: ",k+1);
        scanf("%s",v1);
        if(string_checker(v1)){
        c.instructor_ids[k] = malloc (MAX * sizeof (char));
        strcpy(c.instructor_ids[k],v1);
        }
        else{
        addi_file_d(v1);
        c.instructor_ids[k] = malloc (MAX * sizeof (char));
        strcpy(c.instructor_ids[k],v1);
        }
    }
    printf("Enter the no. of students: ");
    scanf("%d",&c.nstudents);
    c.student_rollnos = malloc (c.nstudents * sizeof(char *));
    printf("Enter the student roll numbers:-\n");
    char v2[20];
    for(int k=0;k<c.nstudents;k++){
        printf("Student Roll Number [%d]: ",k+1);
        scanf("%s",v2);
        if(string_checker(v2)){
        c.student_rollnos[k] = malloc (MAX * sizeof (char));
        strcpy(c.student_rollnos[k],v2);
        }
        else{
        adds_file_d(v2);
        c.student_rollnos[k] = malloc (MAX * sizeof (char));
        strcpy(c.student_rollnos[k],v2);
        }
    }
    add_course(c);
    fpc=fopen(courses_file,"w");
    fprintf(fpc,"%d\n",ncourses);
        for(int h=0;h<ncourses;h++){
        fprintf(fpc,"\n%s\n",courses[h].code);
        fprintf(fpc,"%s\n",courses[h].name);
        fprintf(fpc,"%d\n",courses[h].credits);
        fprintf(fpc,"%d\n",courses[h].ninstructors);
        for(int j=0;j<courses[h].ninstructors;j++){
            fprintf(fpc,"%s ",courses[h].instructor_ids[j]);
        }
        fprintf(fpc,"\n%d\n",courses[h].nstudents);
        for(int j=0;j<courses[h].nstudents;j++){
            fprintf(fpc,"%s ",courses[h].student_rollnos[j]);
        }
        fprintf(fpc,"\n");
        }
	printf("\n\n");
        fclose(fpc);
	printf("\n**Course Code %s added.**\n\n",h1);
    }
}

void addc_file_d(char *z){
    struct course c;
    strcpy(c.code,z);
    strcpy(c.name,char_d);
    c.credits=int_d;
    c.ninstructors=int_d;
    c.instructor_ids = malloc (c.ninstructors * sizeof(char *));
    for(int k=0;k<c.ninstructors;k++){
        c.instructor_ids[k] = malloc (MAX * sizeof (char));
        strcpy(c.instructor_ids[k],char_d);
    }
    c.nstudents=int_d;
    c.student_rollnos = malloc (c.nstudents * sizeof(char *));
    for(int k=0;k<c.nstudents;k++){
        c.student_rollnos[k] = malloc (MAX * sizeof (char));
        strcpy(c.student_rollnos[k],char_d);
    }
    add_course(c);
    fpc=fopen(courses_file,"w");
    fprintf(fpc,"%d\n",ncourses);
        for(int h=0;h<ncourses;h++){
        fprintf(fpc,"\n%s\n",courses[h].code);
        fprintf(fpc,"%s\n",courses[h].name);
        fprintf(fpc,"%d\n",courses[h].credits);
        fprintf(fpc,"%d\n",courses[h].ninstructors);
        for(int j=0;j<courses[h].ninstructors;j++){
            fprintf(fpc,"%s ",courses[h].instructor_ids[j]);
        }
        fprintf(fpc,"\n%d\n",courses[h].nstudents);
        for(int j=0;j<courses[h].nstudents;j++){
            fprintf(fpc,"%s ",courses[h].student_rollnos[j]);
        }
        putc('\n',fpc);
        }
	printf("\n\n");
        fclose(fpc);
}

void mod_student(char *z){
	int pos,f=0;
	for(int i=0;i<nstudents;i++){
		if(strcmp(z,students[i].rollno)==0){
			pos=i;
			f=1;
		}
	}
	if(f==0){
		printf("Student not found.");
	}
	if (f==1){printf("Select data to be modified from the following:-\n 1.Name\n 2.Branch\n 3.Semester\n 4.Courses\n\n");
	printf("Enter your choice: ");
    	int sb;
    	scanf("%d",&sb);
    	putchar('\n');
    	switch(sb)
    	{
    	int c;
    	case 1 : printf("Modified Name: ");
    		 char n1[MAX];
    		 scanf(" %[^\n]s",n1);
    		 strcpy(students[pos].name,n1);
    		 break;

    	case 2 : printf("Modified Branch\n(0 = CSE, 1 = EE, 2 = ME)\nYour Response: ");
    		 scanf("%d",&c);
	    	 students[pos].branch=c;
		 break;

    	case 3 : printf("Modified Semester: ");
    		 scanf("%d",&c);
    		 students[pos].semester=c;
    		 break;

    	case 4 : printf("Modified Number of courses: ");
    		scanf("%d",&c);
    		char s2[20];
    		putchar('\n');
    		students[pos].ncourses=c;
    		students[pos].course_codes=realloc(students[pos].course_codes, c * sizeof(char *));
    		printf("Modified Course Codes:-\n");
    		for (int j=0; j<c; j++)
        	{
            		printf("Enter Modified Course Code [%d]: ",j+1);
            		scanf("%s",s2);
            		if(string_checker(s2)){
            		students[pos].course_codes[j] = malloc (MAX * sizeof (char));
            		scanf("%s", students[pos].course_codes[j]);
            		}
            		else{
                    	addc_file_d(s2);
                   	students[pos].course_codes[j] = malloc (MAX * sizeof (char));
            		scanf("%s", students[pos].course_codes[j]);
            		}
        	}
        	break;
        default:printf("Wrong Option.\nTry again.\n");
        break;
    	}
	fps = fopen(students_file, "w");
	fprintf(fps,"%d\n",nstudents);
        for(int h=0;h<nstudents;h++){
        fprintf(fps,"\n%s\n",students[h].rollno);
        fprintf(fps,"%s\n",students[h].name);
        fprintf(fps,"%u\n",students[h].branch);
        fprintf(fps,"%d\n",students[h].semester);
        fprintf(fps,"%d\n",students[h].ncourses);
        for(int j=0;j<students[h].ncourses;j++){
            fprintf(fps,"%s ",students[h].course_codes[j]);
        }
        fprintf(fps,"\n");
        }
	printf("\n\n");
        fclose(fps);
        printf("**Student Roll Number %s was modified.**\n\n",z);
	}
}

void mod_instructor(char *z){
	int pos,f=0;
	for(int k=0;k<ninstructors;k++){
		if(strcmp(z,instructors[k].id)==0){
			pos=k;
			f=1;
		}
	}
	if(f==0){
		printf("Instructor not found.");
	}
	if (f==1){
	printf("Select data to be modified from the following:-\n 1.ID\n 2.Name\n 3.Courses\n\n");
	printf("Enter your choice: ");
    	int sb;
    	scanf("%d",&sb);
	int c;
    	putchar('\n');
    	switch(sb)
    	{
    	case 1 : printf("Modified ID: ");
    		 char n1[MAX];
    		 scanf("%s",n1);
    		 if(!string_checker(n1)){
                 strcpy(instructors[pos].id,n1);
            }
            else{
                printf("Same Instructor ID already exists.\n");
            }
    		 break;

    	case 2 : printf("Modified Name: ");
                char n2[MAX];
    		 scanf(" %[^\n]s",n2);
	    	 strcpy(instructors[pos].name,n2);
	    	 break;
        case 3:  printf("Modified Number of courses: ");
    		scanf("%d",&c);
    		char s2[MAX];
    		putchar('\n');
    		instructors[pos].ncourses=c;
    		instructors[pos].courses_codes=realloc(instructors[pos].courses_codes, c * sizeof(char *));
    		printf("Modified Course Codes:-\n");
    		for (int j=0; j<c; j++)
        	{
                    printf("Enter Modified Course Code [%d]: ",j+1);
                    scanf("%s",s2);
                    if(string_checker(s2)){
            		instructors[pos].courses_codes[j] = malloc (MAX * sizeof (char));
            		strcpy(instructors[pos].courses_codes[j],s2);
                    }
                    else{
                    	addc_file_d(s2);
                    	instructors[pos].courses_codes[j] = malloc (MAX * sizeof (char));
		    	strcpy(instructors[pos].courses_codes[j],s2);
                        }
        	}
        	break;
        default:printf("Wrong Option.\nTry again.\n");
        	break;
    	}
	fpi = fopen(instructors_file, "w");
	fprintf(fpi,"%d\n",ninstructors);
        for(int h=0;h<ninstructors;h++){
        fprintf(fpi,"\n%s\n",instructors[h].id);
        fprintf(fpi,"%s\n",instructors[h].name);
        fprintf(fpi,"%d\n",instructors[h].ncourses);
        for(int j=0;j<instructors[h].ncourses;j++){
            fprintf(fpi,"%s ",instructors[h].courses_codes[j]);
        }
        putc('\n',fpi);
        }
	printf("\n\n");
        fclose(fpi);
        printf("\n**Instructor ID %s was modified**\n\n",z);
    }
}

void mod_course(char *z){
    int pos,f=0;
	for(int k=0;k<ncourses;k++){
		if(strcmp(z,courses[k].code)==0){
			pos=k;
			f=1;
		}
	}
	if(f==0){
		printf("Course not found.");
	}
	if (f==1){
	printf("Select data to be modified from the following:-\n 1.Code\n 2.Name\n3.Credits\n4.Instructors\n5.Students\n\n");
	printf("Enter your choice: ");
    	int sb;
    	scanf("%d",&sb);
    	putchar('\n');
    	switch(sb){
    	int c;
    	case 1: printf("Modified code: ");
            char n1[MAX];
            scanf("%s",n1);
            if(!string_checker(n1)){
                 strcpy(courses[pos].code,n1);
            }
            else{
                printf("Same course code already exists.\n");
            }
            break;
    	case 2: printf("Modified Name: ");
            char n2[MAX];
            scanf(" %[^\n]s",n2);
            strcpy(courses[pos].name,n2);
            break;
        case 3: printf("Modified Credits: ");
            scanf("%d",&c);
            courses[pos].credits=c;
            break;
        case 4: printf("Modified no. of Instructors: ");
            scanf("%d",&c);
            char s1[20];
    		putchar('\n');
    		courses[pos].ninstructors=c;
    		courses[pos].instructor_ids=realloc(courses[pos].instructor_ids, c * sizeof(char *));
    		printf("Modified Instructor IDs:-\n");
    		for (int j=0; j<c; j++)
        	{
            		printf("Enter Instructor ID [%d]: ",j+1);
            		scanf("%s",s1);
            		if(string_checker(s1)){
                    	courses[pos].instructor_ids[j] = malloc (MAX * sizeof (char));
            		strcpy(courses[pos].instructor_ids[j],s1);
            		}
            		else{
                   	addi_file_d(s1);
                    	courses[pos].instructor_ids[j] = malloc (MAX * sizeof (char));
            		strcpy(courses[pos].instructor_ids[j],s1);
            		}
        	}
        	break;
        case 5: printf("Modified No. of Students: ");
            scanf("%d",&c);
            char s2[20];
            putchar('\n');
            courses[pos].nstudents=c;
            courses[pos].student_rollnos=realloc(courses[pos].student_rollnos,c*sizeof(char *));
            printf("Modified Student Roll Numbers:-\n");
            for(int j=0;j<c;j++){
                printf("Student Roll Number [%d]: ",j+1);
                scanf("%s",s2);
                if(string_checker(s2)){
                courses[pos].student_rollnos[j]=malloc(MAX*sizeof(char));
                strcpy(courses[pos].student_rollnos[j],s2);
                }
                else{
                adds_file_d(s2);
                courses[pos].student_rollnos[j]=malloc(MAX*sizeof(char));
                strcpy(courses[pos].student_rollnos[j],s2);
                }
            }
            break;
         default:printf("Wrong Option.\nTry again.\n");
        	break;
}
fpc = fopen(courses_file, "w");
	fprintf(fpc,"%d\n",ncourses);
        for(int h=0;h<ncourses;h++){
        fprintf(fpc,"\n%s\n",courses[h].code);
        fprintf(fpc,"%s\n",courses[h].name);
        fprintf(fpc,"%d\n",courses[h].credits);
        fprintf(fpc,"%d\n",courses[h].ninstructors);
        for(int j=0;j<courses[h].ninstructors;j++){
            fprintf(fpc,"%s ",courses[h].instructor_ids[j]);
        }
        fprintf(fpc,"\n%d\n",courses[h].nstudents);
        for(int j=0;j<courses[h].nstudents;j++){
            fprintf(fpc,"%s ",courses[h].student_rollnos[j]);
        }
        fprintf(fpc,"\n");
        }
	printf("\n\n");
        fclose(fpc);
	printf("\n**Course Code %s was modified**\n\n",z);
	}
 }


void del_student(char *z){
	int pos,f=0;
	for(int i=0;i<nstudents;i++){
		if(strcmp(z,students[i].rollno)==0){
			pos=i;
			f=1;
		}
	}
	if(f==0){
		printf("\n**Student not found.**\n\n");
	}
	if(f==1){
	for(int i=pos;i<nstudents-1;i++)
    	{
        	students[i]=students[i+1];
   	}
    	nstudents--;
    	students=realloc(students,nstudents * sizeof(struct student));
    	fps = fopen(students_file, "w");
	fprintf(fps,"%d\n",nstudents);
        for(int h=0;h<nstudents;h++){
        fprintf(fps,"\n%s\n",students[h].rollno);
        fprintf(fps,"%s\n",students[h].name);
        fprintf(fps,"%u\n",students[h].branch);
        fprintf(fps,"%d\n",students[h].semester);
        fprintf(fps,"%d\n",students[h].ncourses);
        for(int j=0;j<students[h].ncourses;j++){
            fprintf(fps,"%s ",students[h].course_codes[j]);
        }
        putc('\n',fps);
        }
	printf("\n\n");
        fclose(fps);
        printf("\n**Student Roll Number %s deleted**\n\n",z);
        }
}

void del_instructor(char *z){
	int pos,f=0;
	for(int i=0;i<ninstructors;i++){
		if(strcmp(z,instructors[i].id)==0){
			pos=i;
			f=1;
		}
	}
	if(f==0){
		printf("Instructor not found.");
	}
	if(f==1){
        for(int i=pos;i<ninstructors-1;i++)
    	{
        	instructors[i]=instructors[i+1];
        }
        ninstructors--;
        instructors=realloc(instructors,ninstructors * sizeof(struct instructor));
    	fpi = fopen(instructors_file, "w");
	fprintf(fpi,"%d\n",ninstructors);
        for(int h=0;h<ninstructors;h++){
        fprintf(fpi,"\n%s\n",instructors[h].id);
        fprintf(fpi,"%s\n",instructors[h].name);
        fprintf(fpi,"%d\n",instructors[h].ncourses);
        for(int j=0;j<instructors[h].ncourses;j++){
            fprintf(fpi,"%s ",instructors[h].courses_codes[j]);
        }
        putc('\n',fpi);
        }
	printf("\n\n");
        fclose(fpi);
	    printf("\n**Instructor ID %s deleted**\n\n",z);
        }
}

void del_course(char *z){
    int pos,f=0;
	for(int i=0;i<ncourses;i++){
		if(strcmp(z,courses[i].code)==0){
			pos=i;
			f=1;
		}
	}
	if(f==0){
		printf("Course not found.");
	}
	if(f==1){
        for(int i=pos;i<ncourses-1;i++)
    	{
        	courses[i]=courses[i+1];
        }
        ncourses--;
        courses=realloc(courses,ncourses * sizeof(struct course));
    	fpc = fopen(courses_file, "w");
	fprintf(fpc,"%d\n",ncourses);
        for(int h=0;h<ncourses;h++){
        fprintf(fpc,"\n%s\n",courses[h].code);
        fprintf(fpc,"%s\n",courses[h].name);
        fprintf(fpc,"%d\n",courses[h].credits);
        fprintf(fpc,"%d\n",courses[h].ninstructors);
        for(int j=0;j<courses[h].ninstructors;j++){
            fprintf(fpc,"%s ",courses[h].instructor_ids[j]);
        }
        fprintf(fpc,"\n%d\n",courses[h].nstudents);
        for(int j=0;j<courses[h].nstudents;j++){
            fprintf(fpc,"%s ",courses[h].student_rollnos[j]);
        }
        putc('\n',fpc);
        }
	printf("\n\n");
        fclose(fpc);
	printf("\n**Course Code %s deleted**\n\n",z);
        }
}

int string_checker(char *z){
    for(int k=0;k<nstudents;k++){
        if(strcmp(z,students[k].rollno)==0){
            return 1;
        }
    }
    for(int k=0;k<ninstructors;k++){
        if(strcmp(z,instructors[k].id)==0){
            return 1;
        }
    }
    for(int k=0;k<ncourses;k++){
        if(strcmp(z,courses[k].code)==0){
            return 1;
        }
    }
    return 0;
}
