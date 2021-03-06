#include <iostream>
#include <cstdlib>

using namespace std;

int main();

void twod();

void error();

void float_check(float check){

    if((check < 0) || (check > 0))
    ;
    else
    error();
}

void int_check(int check){

    if((check < 0) || (check > 0))
    ;
    else
    error();
}

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

    }   

}

void error(){     //this function redirects the user

    int choice = 0;

    cout << "An error has occured would you like to restart the program?" << endl;

    for(;;){
        cout << "Press 1 to restart | Press 2 to exit: ";
        cin >> choice;

        if(choice == 1)
            main();
        else if(choice == 2)
            exit(0);
        else
            error();
    }
}

void oned(float constant,float delta_time){

   
    float length = 0;
    float delta_u = 0;
    float change_time = 0;
    int segments = 0;
    int right_temp = 0;
    int left_temp = 0;


    cout << "How many segments do you want?: ";
    cin >> segments;
    
    cout << "What is the temp of the right side?: ";
    cin >> right_temp;
    
    cout << "What is the temp of the left side? :";
    cin >> left_temp;
    
    change_time = delta_time;
  
        float* array1 = new float[segments];
        float* array2 = new float[segments];
  
    for(int i = 0; i < segments;i++){
        
        array1[i] = 0;
        array2[i] = 0;
    }
    
    array1[segments-1] = right_temp;
    array2[segments-1] = right_temp;
    
    array1[0] = left_temp;
    array2[0] = left_temp;
    
    for(int i=0; i < segments; i++){
        
        for(int j = 1; j < (segments-1);j++){
            delta_u = ((array1[j+1]) - (2*(array1[j])) + (array1[j-1]));
            array1[j] = (((constant * change_time * delta_u) / (j^2))+array1[j]);
        }
        
        cout << endl;
      
        for(int a = 0;a < segments;a++){
            cout << array1[a] << " ";
            array1[a] = array2[a];
        
        change_time = change_time + delta_time;
        
        }
    }
        
        
    delete [] array1;
    delete [] array2;
}

void twod(float constants,float delta_time){
    
    float height_temp = 0;
    float width_temp = 0;
    float change_time = 0;
    int length = 0;

    cout << "What is the temp of the top and bottom?: ";
    cin >> height_temp;
    
    cout << "What is the temp of the right and left?: ";
    cin >> width_temp;
    
    cout << "How long is the object?: ";
    cin >> length;
    
    
    float** array1 = new float*[length];
    float** array2 = new float*[length];
    
    for(int i = 0;i < length;i++ ){
           
            array1[i] = new float[length];
            array2[i] = new float[length];
        
    }
    
    for(int i = 0;i < length;i++){
        for(int j = 0;j < length;j++){
            
            array1[i][j] = 0;
            array2[i][j] = 0;
        }
    }
    
    
    for(int i = 0;i <length; i++){
    
            array1[i][0] = width_temp;
            array2[i][0] = width_temp;
        
            array1[0][i] = height_temp;
            array2[0][i] = height_temp;
          
            array1[i][length - 1] = width_temp;
            array2[i][length - 1] = width_temp;
        
            array1[length - 1][i] = height_temp;
            array2[length - 1][i] = height_temp;
        
    }
    
    for(int i = 0;i < length;i++ ){
        for(int j = 0;j < length;j++){
            
            cout << array1[i][j] <<  " ";

        }

        cout << endl;        
    }


    cout << endl;
float twod( constants,float delta_time){

    float height_temp = 0;
    float width_temp = 0;
    float change_time = 0;
    int length = 0;

    cout << "What is the temp of the top and bottom?: ";
    cin >> height_temp;

    cout << "What is the temp of the right and left?: ";
    cin >> width_temp;

    cout << "How long is the object?: ";
    cin >> length;


    float** array1 = new float*[length];
    float** array2 = new float*[length];

    for(int i = 0;i < length;i++ ){

            array1[i] = new float[length];
            array2[i] = new float[length];

    }

    for(int i = 0;i < length;i++){
        for(int j = 0;j < length;j++){

            array1[i][j] = 0;
            array2[i][j] = 0;
        }
    }

    
    for(int i = 0;i <length;i++){
        for(int j = 1;j < (length - 1);j++){
            for(int k = 1;k <(length - 1);k++){
                array1[j][k] = (change_time * constants * ((((array1[j+1][k])-(2*array1[j][k])+(array1[j-1][k]))/(k^2))+(((array1[j][k+1])-(2*array1[j][k])+(array1[j][k-1]))/(j^2))) + array1[j][k]);
                
            }
            cout << endl;
        }
        cout << endl;
        
    }
  
    for(int i = 0;i < length;i++){
    
        delete [] array1[i];
        delete [] array2[i];
    }
    
    delete [] array1;
    delete [] array2;
    
;    
    
    
}


int main(){
         
    int choice = 0; 
    float thermal_conductivity = 0;
    float material_density = 0;
    float specific_heat = 0;
    float time = 0;
    float delta = 0;
    int time_interval = 0;
    float constant = 0;
         
    cout << "Welcome to thermal diffussion calculator!" << endl;
    cout << "What is the thermal conductivity of the material?: ";
    cin >> thermal_conductivity;
    
    float_check(thermal_conductivity);

    cout << "What is the material density of the object?: ";
    cin >> material_density;
    
    float_check(material_density);
    
    cout << "What is the specific heat of the object?: ";
    cin >> specific_heat;

    float_check(specific_heat);

    cout << "How long will the reaction take?: ";
    cin >> time;
    
    float_check(time);
    
    cout << "How many time intervals will there be?: ";
    cin >> time_interval;
    
    int_check(time_interval);
    
    cout << "Is the object 1-d or 2-d?" << endl;
    cout << "Press 1 for 1-d | press 2 for 2-d: ";
    cin >> choice;
    
    delta = time / time_interval;
    
    constant = (thermal_conductivity / (specific_heat * material_density));

    if(choice == 1) 
        oned(constant,delta );
    else if(choice == 2)
        twod(constant,delta);
    else
        error();       
    
    
return 0;
}


