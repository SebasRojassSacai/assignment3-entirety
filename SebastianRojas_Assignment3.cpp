//Sebastian Rojas
//Assignment 3
//10/4/2023
//Purpose of this assignment is to Write a program to compute average numeric grades for a course. 
#include <iostream>
#include <fstream>
#include <vector> 
#include <cstdlib>
#include <string>
#include <sstream>


using namespace std;

struct StudentInfo {
    string last_name;
    string first_name;
    vector<int> scores;
    int num_scores;
};
StudentInfo generate_student(string first_name, string last_name) {
    StudentInfo student;

    student.first_name = last_name;
    student.last_name = first_name;
    student.num_scores = rand() % 10 + 1;

    for (int j = 0; j < student.num_scores; j++) {
        int score = rand() % 20 + 1;
        student.scores.push_back(score);
    }
    return student;
}
void generate_input() {
    ofstream input_file("input.txt");
    vector<StudentInfo> students;

    // Write input data
    students.push_back(generate_student("Rojas", "Sebas"));
    students.push_back(generate_student("Kanth", "Rosh"));
    students.push_back(generate_student("Moe", "Max"));
    students.push_back(generate_student("Ake", "Owen"));
    students.push_back(generate_student("Tom", "Shar"));


    for (StudentInfo student : students) {
        input_file << student.last_name << " " << student.first_name << " ";
        for (int score : student.scores) {
            input_file << score << " ";
        }
        input_file << endl;
    }

    // Close input file after writing
    input_file.close();
}
void generate_output() {
    // Open input file for reading
    ifstream input_file_("input.txt");

    // Open output file for writing
    ofstream output_file("output.txt");

    string line;

    // Read lines and process scores
    while (getline(input_file_, line)) {

        StudentInfo student;
        stringstream ss(line);
        ss >> student.last_name >> student.first_name;

        int score;
        while (ss >> score) {
            student.scores.push_back(score);
        }

        double average_grade = 0.0;
        for (int score : student.scores) {
            average_grade += score;
        }
        average_grade /= student.scores.size();

        // Output to console
        cout << student.last_name << " " << student.first_name << ": ";
        for (int score : student.scores) {
            cout << score << " ";
        }
        cout << "| Average: " << average_grade << endl;
        // Output to file
        output_file << student.last_name << " " << student.first_name << " ";
        for (int score : student.scores) {
            output_file << score << " ";
        }
        output_file << average_grade << endl;
    }

    // Close files after processing
    input_file_.close();
    output_file.close();
}
int main() {

    // Seed the random number generator
    srand(time(NULL));

    generate_input();

    generate_output();
    return 0;

}