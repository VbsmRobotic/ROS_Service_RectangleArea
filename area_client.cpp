#include "ros/ros.h"
#include "ros_service_assignment/RectangleArea.h"
#include<cstdlib>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Area_Rectangle_client") ;
    if(argc != 3)
    {
        ROS_INFO("usage: Area_Rectangle_client X Y") ;
        return 1 ;
    }
    ros::NodeHandle nh ;
    ros::ServiceClient  client = nh.serviceClient<ros_service_assignment::RectangleArea> ("Area_Rectangle") ;
    ros_service_assignment::RectangleArea srv ;
    srv.request.h = atof(argv[1]) ;
    srv.request.w = atof(argv[2]) ;

    if (client.call(srv))
    {
        ROS_INFO("Area:%f ", (float)srv.response.area) ;
    }else
    {
        ROS_ERROR("Failed to call service Area") ;
        return 1 ;
    }

    return 0 ;    

}