#include <iostream>
#include <cstdlib>

using namespace std;

int main();

void error();

void print_array(float **diffusion,int time,float time_i,int seg);

void repeat();

void repeat(){

    int choice = 0;

    cout << "Would you like to repeat the program?" << endl;

    for(;;){
   
    cout << "Press 1 to restart | Press 2 to exit: ";
    cin >> choice;
  
    if(choice == 1)
        main();
    else if(choice == 2)
        exit(0);
    else 
        error();

}}

void error(){

    int choice = 0;

    cout << "An error has occured would you like to restart the program?" << endl;
    
    for(;;){
        cout << "Press 1 to restart | Press 2 to exit";
        cin >> choice;
    
        if(choice == 1)
            main();
        else if(choice == 2)
            exit(0);
        else
            error();
    }
}  

void oned(){

    float **array;
    float change_position = 0;
    float constant = 0;
    float position = 0;
    int segments = 0;
    int timecount = 0;
    float change_segments = 0;
    float length = 0;
    float specific_heat = 0;
    float left_temp = 0;
    float right_temp = 0;
    float time_initial = 0;
    float time_final = 0;
    int time_int = 0;
    float time_seg = 0;
    float therm_conduct = 0;
    float mat_den = 0;
    float time_total = 0;
    float diffusion = 0;
    float diffusion_x = 0;
    int segcount = 0;
    float change_time = 0;

    cout << "Welcome to the 1-d diffusion calculator!" << endl;
    cout << "Keep in mind that this program will incrment by 1 second by default" << endl;
    cout << "Please enter the length of u: ";
    cin >> length;

    cout << "Please enter the inital time: ";
    cin >> time_initial;

    cout << "Please enter the final time: ";
    cin >> time_final;

    cout << "How often do you want your time itervals to be?: ";
    cin >> time_int;

    cout << "What is the specific heat capacity of the material?: ";
    cin >> specific_heat;

    cout << "What is the thermal conductivity of u?: ";
    cin >> therm_conduct;

    cout << "What is the density of the substance?: ";
    cin >> mat_den;

    cout << "How many segments do you want?: " << endl;
    cin >> segments;

    cout << "What is the right temp of the object?: ";
    cin >> right_temp;

    cout << "What is the left temp of the object?: ";
    cin >> left_temp;

    time_total = time_final - time_initial;

    time_seg = time_total / time_int;

    change_position = length / segments;


        array = new float* [time_int];
     
    for(int i = 0;i < time_int;i++){
        for(int j = 0;j < segments;j++){

            array[i] = new float;
                
        } 
    }

    for(int i = 0;i < time_int;i++){
        for(int j = 0; j < segments;j++){
 
           array[i][j] = 0;

        }   

    }

    for(int i = 0;i < time_int;i++){
        array[i][0] = left_temp;
        array[i][segcount] = right_temp;
    }
 
    constant = (therm_conduct / (specific_heat * mat_den));

    for(int i = 0;i < time_int;i++){ // i is time in this case

       for(int j = 1; j < (segments - 1);j++){

           array[i][j] = (change_time * constant * (array[i][j+1] - 2 * array[i][j] + array[i][j-1])/(change_segments * change_segments));
 
           change_segments = change_segments + change_position;

       }

       change_time = change_time + time_seg;
    }

    
    for(int i = 0;i < time_int;i++){

        cout << endl;

        for(int j = 0;j < segments;j++){

            cout << array[i][j];

        }

    }

    for(int i = 0;i < time_int;i++){

        delete[] array[i];


    }

    delete[] array;

//       print_array(array,time_total,time_int,segments);

return; 
}

void twod(){

}

/*
void print_array(float **diffusion,int time,float time_i,int seg){

    for(int i = 0;i < time;i + time_i){
        cout << endl;
        for(int j = 0;j < seg;j++){
         
            cout << diffusion[i][j]; 
        

        }
    }

} */

int main(){

    int choice = 0;

    cout << "Welcome to thermal diffussion calculator!" << endl;
    cout << "Would you like to calculate the diffussion of 1-D or 2-D object?" << endl;
    cout << "Press 1 for 1-D | Press 2 for 2-D: ";
    cin >> choice;

    if(choice == 1)
        oned();
    else if(choice == 2)
        twod();
    else
        error();       


return 0;
}
