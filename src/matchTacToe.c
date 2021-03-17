#include <stdio.h>
#include <application.h>

int main(void){

    //setup stuff
    application_init();
    
    //enter game loop
    while(application_QUIT == FALSE){
    
        //shows the ui to the user
        application_display();
    
        // takes in player input and performs error checking
        application_getInput();

        // updates the state of the application based on the users input
        application_update();
        
    }//end game loop

    //punish / reward the matchboxes and save the information
    // and do necessary cleanup
    application_shutDown();

    return 0;
}
