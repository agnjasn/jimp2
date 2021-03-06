//
// Created by agnieszka on 21.05.17.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <iostream>
#include <vector>
#include <map>
#include <set>
namespace academia
{
    class SchedulingItem
    {
    public:
        virtual ~SchedulingItem() {}
        SchedulingItem(){}
        SchedulingItem(int course_id,int teacher_id,
                       int room_id, int time_slot,int year) :
                course_id_(course_id), teacher_id_(teacher_id),
                room_id_(room_id), time_slot_(time_slot), year_(year){}

        int CourseId() const {return course_id_;}
        int TeacherId() const {return teacher_id_;}
        int RoomId()const {return room_id_;}
        int TimeSlot()const { return  time_slot_;}
        int Year()const { return year_;}

    private:
        int course_id_;
        int teacher_id_;
        int room_id_;
        int time_slot_;
        int year_;
    };


    class Schedule
    {
    public:
        Schedule(){}
        virtual ~Schedule(){};
        Schedule OfTeacher(int teacher_id) const;
        Schedule OfRoom(int room_id) const;
        Schedule OfYear(int year) const;
        std::vector<int> AvailableTimeSlots(int n_time_slots) const;
        void InsertScheduleItem(const SchedulingItem &item);
        size_t Size() const;

        SchedulingItem operator[] (int val) const;

    private:
        std::vector<SchedulingItem> courses_;
    };


    class Scheduler
    {
    public:
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots)=0;
    private:
//        std::vector<int> rooms;
//        std::map<int, std::vector<int>> teacher_courses_assignment;
//        std::map<int, std::set<int>> courses_of_year;
//        int n_time_slots;
    };

    class GreedyScheduler: public Scheduler
    {
    public:
        GreedyScheduler(){}
        Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) override;
    private:
    };

    class NoViableSolutionFound
    {
    public:
    private:
    };

}
#endif //JIMP_EXERCISES_SCHEDULER_H
