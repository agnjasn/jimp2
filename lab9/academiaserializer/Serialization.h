//
// Created by agnieszka on 09.05.17.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include<iostream>
#include<string>
#include <vector>
#include <initializer_list>
#include <sstream>
#include <functional>
#include <experimental/optional>

namespace academia
{
    class Serializer;
    class Serializable {
    public:
        virtual ~Serializable(){}

        Serializable(){}

        virtual void Serialize (Serializer *serial) const=0;
    };

    class Serializer {
    public:
        Serializer(){}

        virtual ~Serializer(){}

        virtual void IntegerField(const std::string &field_name, int value)=0;

        virtual void DoubleField(const std::string &field_name, double value)=0;

        virtual void StringField(const std::string &field_name, const std::string &value)=0;

        virtual void BooleanField(const std::string &field_name, bool value)=0;

        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value)=0;

        virtual void ArrayField(const std::string &field_name, const std::vector <std::reference_wrapper<const academia::Serializable>> &value)=0;

        virtual void Header(const std::string &object_name)=0;

        virtual void Footer(const std::string &object_name)=0;

        Serializer(std::ostream *out);

    protected:
        std::ostream* out_;
    };

    class XmlSerializer: public Serializer
    {
    public:
        XmlSerializer(){}
        virtual ~XmlSerializer(){}
        XmlSerializer(std::ostream *out):Serializer(out){}
        void IntegerField(const std::string &field_name, int value) override;

        void DoubleField(const std::string &field_name, double value) override;

        void StringField(const std::string &field_name, const std::string &value) override;

        void BooleanField(const std::string &field_name, bool value) override;

        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;

        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;

        void Header(const std::string &object_name) override;

        void Footer(const std::string &object_name) override;

    };

    class JsonSerializer: public Serializer
    {
    public:
        JsonSerializer(){};
        virtual ~JsonSerializer(){};
        JsonSerializer(std::ostream *out):Serializer(out){}
        void IntegerField(const std::string &field_name, int value) override;

        void DoubleField(const std::string &field_name, double value) override;

        void StringField(const std::string &field_name, const std::string &value) override;

        void BooleanField(const std::string &field_name, bool value) override;

        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;

        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;

        void Header(const std::string &object_name) override;

        void Footer(const std::string &object_name) override;
    };


    class Room: public Serializable
    {
    public:
        enum class Type {
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };
        std::string EnumToString() const;
        Room() {}
        Room(int id, std::string name, Type type): Id(id), name_(name), type_(type){}
        void Serialize (Serializer *serial) const override ;

    private:
        int Id;
        std::string name_;
        Type type_;
    };

    class Building: public  Serializable
    {
    public:
       // friend  BuildingRepository;
        Building(){}
        virtual ~Building(){}
        Building(int id, std::string number, std::initializer_list<std::reference_wrapper<const Serializable>> room):
                Id(id), number_(number), room_(room){} ;
        void Serialize(Serializer*) const override;

    private:
        int Id;
        std::string number_;
        std::vector<std::reference_wrapper<const Serializable>> room_;
    };

    class BuildingRepository
    { public:
        //friend Building;
        BuildingRepository(){}
        virtual ~BuildingRepository(){}
        BuildingRepository(Room room_): room(room_){}
        BuildingRepository(Building build_, Room room_): build(build_), room(room_){}
        std::experimental::optional<Building>& operator[](int value);
        void Add(Building& room);
        void StoreAll(Serializer *serializer) const;

    private:
        Building build;
        Room room;

    };

}
#endif //JIMP_EXERCISES_SERIALIZATION_H

