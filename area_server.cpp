#include <iostream>
#include "ros/ros.h"
#include "ros_service_assignment/RectangleArea.h"

using namespace std ;

bool area(ros_service_assignment::RectangleAreaRequest  &req, ros_service_assignment::RectangleAreaResponse &res)
{
    res.area = req.h * req.w ;
    ROS_INFO("request: x=%f, y=%f",  (float)req.h, (float)req.w) ;
    ROS_INFO("sending back response: [%f]", (float)res.area ) ;
    return true ;

}



int main(int argc, char **argv)
{
    ros::init(argc, argv, "Area_Rectangle_server") ;
    ros::NodeHandle nh ;

    ros::ServiceServer service = nh.advertiseService("Area_Rectangle", area) ;
    ROS_INFO("Ready to Area Rectangle.") ;
    ros::spin() ;
    
    return 0 ;
}