//
//  main.cpp
//  cplusplusfun
//
//  Created by Adam Veary on 2/23/16.
//  Copyright © 2016 Adam Veary. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <string>

int main(int argc, const char * argv[]) {
    
    // notifications = array of epoch notification times
    std::string notifications[] = {"1456323204", "1456150404", "1456668804", "1456841604"};
    
    // now = current epoch time
    time_t now;
    time(&now);
    
    int size = sizeof(notifications) / sizeof(std::string);
    
    double timediff;
    struct tm * notificationTimeTm;
    
    for(int i = 0; i < size; i++) {
        time_t notificationTime = (time_t) notifications[i].c_str();
        notificationTimeTm = localtime(&notificationTime);
        
        timediff = difftime(now, mktime(notificationTimeTm));
        
        // this output doesnt look right so something is off here
        std::cout << std::to_string(timediff) << "\n";
    }
    
    struct tm * nowTm;
    nowTm = localtime(&now);
    
    std::cout << "set hours too: " << nowTm->tm_hour << "\n";
    std::cout << "set minutes too: " << nowTm->tm_min << "\n";
    
    
    return 0;
}
