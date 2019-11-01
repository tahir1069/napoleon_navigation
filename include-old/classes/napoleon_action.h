#ifndef NAP_ACT_H
#define NAP_ACT_H

#include <algorithm>    // std::rotate
#include <geometry_msgs/Twist.h>
#include <ros/ros.h>
#include "napoleon_config.h"
#include "napoleon_functions.h"

#include "napoleon_model.h"
#include "napoleon_prediction.h"

class NapoleonModel;
class NapoleonPrediction;

class NapoleonAction{

public:

    geometry_msgs::Twist cmd_vel;
    
public:

    NapoleonAction(){

    }

    void update(ros::Publisher &vel_pub, NapoleonModel &M, NapoleonPrediction &P);
    void stop(ros::Publisher &vel_pub);

};

#endif