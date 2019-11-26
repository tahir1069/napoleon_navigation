//
// Created by bob on 25-09-19.
//

#ifndef NAVIGATION_POSE2D_H
#define NAVIGATION_POSE2D_H

#include "Vector2D.h"
#include <iostream>

class Pose2D : public Vector2D {
public:
    double a;

    Pose2D(Vector2D p, double a_) : Vector2D(p.x, p.y){
        a = a_;
    }
    Pose2D(double x_, double y_, double a_) : Vector2D(x_, y_){
        a = a_;
    }
    Pose2D() : Vector2D(0, 0){
        a = 0;
    }
    void rotateOrientation(double t){
        a += t;
    }
    Pose2D operator+ (const Pose2D& other)const{
        Pose2D p;
        p.x = this->x + other.x;
        p.y = this->y + other.y;
        p.a = this->a + other.a;
        return p;
    }
    Pose2D operator- (const Pose2D& other)const {
        Pose2D p;
        p.x = this->x - other.x;
        p.y = this->y - other.y;
        p.a = this->a - other.a;
        return p;
    }
    Pose2D operator* (double s)const{
        Pose2D p;
        p.x = this->x * s;
        p.y = this->y * s;
        p.a = this->a * s;
        return p;
    }
    Pose2D operator/ (double s)const{
        Pose2D p;
        p.x = this->x / s;
        p.y = this->y / s;
        p.a = this->a / s;
        return p;
    }
    bool operator> (const Pose2D& other)const{
        return (this->x > other.x && this->y > other.y && this->a > other.a);
    }
    bool operator< (const Pose2D& other)const{
        return (this->x < other.x && this->y < other.y && this->a < other.a);
    }
    void unitPoseThis(){
        Vector2D v(x,y);
        if(v.length() > 0.0001){
            v = v/v.length();
        }else{
            v.x = 0;
            v.y = 0;
        }
        x = v.x;
        y = v.y;
        double a_ = a;
        if(abs(a_) > 0.0001){a = a_/abs(a_);}
        else{a = 0;}
    }
    Pose2D unitPose()const{
        Vector2D v(x,y);
        if(v.length() > 0.0001){
            v = v/v.length();
        }else{
            v.x = 0;
            v.y = 0;
        }
        double a_;
        if(abs(a) > 0.0001){a_ = a/abs(a);}
        else{a_ = 0;}
        return {v,a_};
    }
    Vector2D toVector()const{
        return {x,y};
    }
    void constrainThis(double x_, double y_, double a_){
        this->x = abs(this->x) > abs(x_) ? (this->x/abs(this->x)) * abs(x_) : this->x;
        this->y = abs(this->y) > abs(y_) ? (this->y/abs(this->y)) * abs(y_) : this->y;
        this->a = abs(this->a) > abs(a_) ? (this->a/abs(this->a)) * abs(a_) : this->a;
    }
    void constrainThis(double v_, double a_){
        if(this->length() > v_){
            Vector2D newV = this->toVector().unit()*v_;
            this->x = newV.x;
            this->y = newV.y;
        }
        this->a = abs(this->a) > abs(a_) ? (this->a/abs(this->a)) * abs(a_) : this->a;
    }
    void print(const string &name){
        cout << name << " > x:" << this->x << " y:" << this->y << " a:" << this->a << endl;
    }
//    void constrainAngle_Zero_TwoPi(){
//        a = fmod(a, M_PI*2);
//        if (a < 0) a += M_PI*2;
//    }
//
//    void constrainAngle_MinusPi_Pi(){
//        a = fmod(a + M_PI, M_PI*2);
//        if (a < 0) a += M_PI*2;
//        a -= M_PI;
//    }

};

#endif //NAVIGATION_POSE2D_H