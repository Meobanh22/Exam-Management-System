#pragma once

#include <string>
#include "ds.h"

struct Subject {
    std::string subjectID;
    std::string subjectName;
};

struct ExamSlot {
    std::string subjectID;
    std::string subjectName;
    std::string roomID;
    int slotID;
    int studentCount;
};

int addSubject(const Subject& subj);
int getAllSubjects(DynamicArray<Subject>& outList);
int buildConflictGraph();
bool hasConflict(const std::string& subjA, const std::string& subjB);
int generateSchedule(DynamicArray<ExamSlot>& outSlots);
