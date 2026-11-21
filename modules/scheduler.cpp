#include "ds.h"
#include <string>

struct Subject {
    std::string subjectId;
    std::string subjectName;
};

struct ExamSlot {
    std::string subjectId;
    std::string subjectName;
    int slotId;
    int studentCount;
};

static Graph subjectGraph;
static Subject subjects[MAX_VERTICES];
static int subjectCount = 0;
static int studentCounts[MAX_VERTICES] = {0};

static int findSubjectIndex(const std::string& subjectId){
    for(int i = 0; i < subjectCount; i++){
        if (subjects[i].subjectId == subjectId){
            return i;
        }
    }
    return -1;
}

int addSubject(const Subject& subj){
    if (findSubjectIndex(subj.subjectId) == -1) {
        if (subjectCount < MAX_VERTICES) {
            int index = subjectGraph.addVertex(subjectCount);
            if ( index == -1) return -1;
            subjects[subjectCount] = subj;
            subjectCount++;
            return 0;
        }
    }
    return -1;
}
int getAllSubjects(DynamicArray<Subject>& outList){
    for (int i = 0; i < subjectGraph.size(); i++){
        outList.push_back(subjects[i]);
    }
    return 0;
}
int buildConflictGraph(){
    DynamicArray<Student> studentList;
    getAllStudents(studentList);
    if (studentList.size() == 0) return -1;

    for (int i = 0; i < subjectCount; i++) {
        studentCounts[i] = 0;
    }
    for (int i = 0; i < studentList.size(); i++) {
        Student& st = studentList[i];
        for (int j = 0; j < st.subjects.size(); j++) {
            int idx = findSubjectIndex(st.subjects[j]);
            if (idx != -1) studentCounts[idx]++;
        }
    }

    for (int i = 0; i < studentList.size(); i++) {
        Student& st = studentList[i];
        for (int a = 0; a < st.subjects.size(); a++) {
            for (int b = a + 1; b < st.subjects.size(); b++) {
                int idxA = findSubjectIndex(st.subjects[a]);
                int idxB = findSubjectIndex(st.subjects[b]);
                if (idxA != -1 && idxB != -1) {
                    subjectGraph.addEdge(idxA, idxB);
                }
            }
        }
    }
    return 0;
}
bool hasConflict(const std::string& subjA, const std::string& subjB){
    int idxA = findSubjectIndex(subjA);
    int idxB = findSubjectIndex(subjB);
    if (idxA == -1 || idxB == -1) {
        return false;
    }
    return subjectGraph.hasEdge(idxA, idxB);
}
int generateSchedule(DynamicArray<ExamSlot>& outSlots) {
    if (subjectCount == 0) return -1;

    int order[MAX_VERTICES];
    for (int i = 0; i < subjectCount; i++) {
        order[i] = i;
    }
    for (int i = 0; i < subjectCount; i++) {
        for (int j = i + 1; j < subjectCount; j++) {
            if (subjectGraph.getDegree(order[i]) < subjectGraph.getDegree(order[j])) {
                int temp = order[i];
                order[i] = order[j];
                order[j] = temp;
            }
        }
    }

    int colors[MAX_VERTICES];
    for (int i = 0; i < subjectCount; i++) {
        colors[i] = -1;
    }

    int currentSlot = 1;
    int colorsUsed = 0;
    while (colorsUsed < subjectCount) {
        for (int i = 0; i < subjectCount; i++) {
            int u = order[i];
            if (colors[u] == -1) {
                bool canColor = true;
                for (int j = 0; j < subjectCount; j++) {
                    if (subjectGraph.hasEdge(u, j) && colors[j] == currentSlot) {
                        canColor = false;
                        break;
                    }
                }
                if (canColor) {
                    colors[u] = currentSlot;
                    colorsUsed++;
                }
            }
        }
        currentSlot++;
    }

    for (int i = 0; i < subjectCount; i++) {
        ExamSlot slot;
        slot.subjectId = subjects[i].subjectId;
        slot.subjectName = subjects[i].subjectName;
        slot.slotId = colors[i];
        slot.studentCount = studentCounts[i];
        outSlots.push_back(slot);
    }
    return 0;
}