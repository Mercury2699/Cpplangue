#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

const int maxStudents = 20;
const int maxAssignments = 10;

int numAssign = 5;

//array to store student userids
string students[maxStudents];

//array to store student final marks
int marks[maxStudents];

//array to store course component weighs
int weighs[maxAssignments + 2];

//array to store course max marks
int maxMarks[maxAssignments + 2];


int stuCount = 0;

/* 
 * Add additional arrays or globals here
 * if needed e.g. to store assignment and exam 
 * max marks, weights , adjusted weights for a student etc
 */



/*
 * Reads from standard input the course description
 * Stores this information in some global variables
 */
void readCourseInfo(){
    for (int i = 0; i < numAssign + 2; i++) {
        cin >> maxMarks[i] >> weighs[i];
    }
}


/*
 * Reads from standard input student records.
 * If a student record is invalid, produces desired output
 * If student record is valid, computes and stores student's
 * final mark in the course
 */
void readStudentRecords(){
    while (!cin.eof()) {
        string name;
        int stu[numAssign + 2];
        bool acc[numAssign];
        string input;
        getline(cin, input);
        stringstream stream{input};
        stream >> ws;
        if (!stream.eof()){
            stream >> name; 
            int metaScore = 0;
            int num;
            string word;
            bool valid = false;
            for(int i = 0; (i < numAssign + 2) &&  // within range
                            (stream >> word) && // can still read
                            (!stream.eof() || i == numAssign + 1); i++) {
                // reinit array to default
                stu[i] = 0;
                acc[i] = false;
                stream >> ws;
                if (i >= numAssign + 1) { // if read enough but there's more
                    if (!stream.eof()) break; 
                }
                if (word == "ACC"){
                    if (i >= numAssign) { // no ACC on exams
                        break;
                    }
                    acc[i] = true; // mark ACC for future calculation
                } else if ((stringstream(word) >> num) && 
                            (num <= maxMarks[i]) && (num >= 0)){
                    stu[i] = num; // valid normal grade
                } else {
                    break;
                }
                stream >> ws;
                if (i == numAssign + 1) valid = true;
            }
            if (valid) {
                if(stuCount >= 20) {
		    cerr << "Program can only handle 20 valid students!" << endl;
		    cerr << "21st valid student found so terminating. Output might be invalid!" << endl;
		    return;
		}
		int adjust[numAssign + 2];
                for(int i = 0; i < numAssign + 2; i++) {
                    adjust[i] = weighs[i];
                }
                // here we process adjust[] according to acc[]
                for (int i = 0; i < numAssign; ++i) {
                    if (acc[i]) { // if an assignment is marked ACC
                        if (i >= numAssign - 1) { // if it's last assignment
                            adjust[numAssign + 1] += adjust[numAssign - 1];
                            break;
                        }
                        for (int j = i + 1; j < numAssign; j++){ 
                            adjust[j] += adjust[i] / (numAssign - i - 1);
                            if (j >= numAssign - 1) {
                                adjust[j] += adjust[i]%(numAssign - i - 1);
                            }
                        }
                        adjust[i] = 0;
                    }
                }

                // cout << "Original weight" << endl; 
                // for (int i = 0; i < numAssign + 2; i++) {
                //     cout << weighs[i] << endl;
                // }
                
                // cout << "Adjusted weight for " << name << endl; 
                // for (int i = 0; i < numAssign + 2; i++) {
                //     cout << adjust[i] << endl;
                // }

                for (int i = 0; i < numAssign + 2; i++) {
                    // cout << "Calculating for " << name << " " << i << ": " << stu[i] << " * " << adjust[i] << " / " << maxMarks[i] << endl;
                    int part = (stu[i] * adjust[i]) / maxMarks[i];
                    metaScore += part;
                    // cout << metaScore << " -> " << part << endl;
                }
                
                marks[stuCount] = metaScore;
                students[stuCount] = name;
                stuCount++;

            } else { // invalid line input
                cout << name << " invalid" << endl;
            }
        }
    }
}

/*
 * Prints the desired output for student's with valid records
 */
void printResults(){

    // cout << "CourseInfo:" << endl;
    // for (int i = 0; i < numAssign + 2; i++) {
    //     cout << maxMarks[i] << ", " << weighs[i] << endl;
    // }


    cout << "Valid records: " << stuCount << endl;
    int total = 0;
    for (int i = 0; i < stuCount; i++) {
        cout << students[i] << " " << marks[i] << endl;
        total += marks[i];
    }
    int avg = 0;
    if (stuCount != 0) {
        avg = total / stuCount;
    }
    
    cout << "Average: " << avg << endl;
}

int main(int argc, char *argv[]) {
  
    if (argc != 3 && argc != 2) {
        cerr << "Course name not given as arg" << endl;
        exit(0);
    }

    cout << argv[1] << endl;

    if (argc == 3) {
        numAssign = stoi(argv[2]);
        if (numAssign < 0 || numAssign > 10) {
            cerr << "Invalid arg: " << numAssign << endl;
            exit(0);
        }
    }
  
    readCourseInfo();
    readStudentRecords();
    printResults();
}
