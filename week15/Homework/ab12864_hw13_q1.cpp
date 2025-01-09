#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;

//character denotation
const char ANT_CHAR = 'o';
const char DOODLEBUG_CHAR = 'X';
const char SPACE_CHAR = '-';

const int GRID_SIZE = 20;

//start number of critters
const int START_ANTS = 100, START_DOODLEBUGS = 5;

//moves to breed
const int ANT_BREED_MOVE = 3, DOODLEBUG_BREED_MOVE = 8;

//moves to starve - doodlebug
const int DOODLEBUG_STARVE_MOVE = 3;

//ints for ant and doodlebug
const int ANT_TYPE = 1;
const int DOODLEBUG_TYPE = 2;

class Organism{
    public:
        Organism();
        int get_row() const;
        void set_row(int the_row);
        int get_col() const;
        void set_col(int the_col);
        virtual void move();
        virtual int get_type() = 0;
    private:
        int row;
        int col;
};

class Universe{
    public:
        Universe();
        void initialize_universe();
        //void simulate_time_step();
        //bool check_space_empty(Organism arr[], int the_index);
        void display_grid();
    private:
        Organism* grid[GRID_SIZE][GRID_SIZE];
        int num_of_timesteps;
};

class Ant: public Organism{
    public:
        Ant();
        virtual void move();
        void breed();
        virtual int get_type();
};

class Doodlebug: public Organism{
    public:
        Doodlebug();
        virtual void move();
        void breed();
        void starve();
        void eat();
        virtual int get_type();
};

int main(){

    Universe uni1;
    uni1.initialize_universe();
    uni1.display_grid();

    return 0;
}

//Universe class implementation
Universe::Universe():num_of_timesteps(0){
    for (int i = 0; i < GRID_SIZE; i++){
        for (int j = 0; j < GRID_SIZE; j++){
            grid[i][j] = nullptr;
        }
    }
}

void Universe::initialize_universe(){

    srand(time(0));

    for (int i = 0; i < START_ANTS; i++){

        int row = rand()%20;
        int col = rand()%20;

        while(grid[row][col] != nullptr){
            row = rand()%20;
            col = rand()%20;
        }
        grid[row][col] = new Ant;
    }

    for (int i = 0; i < START_DOODLEBUGS; i++){

        int row = rand()%20;
        int col = rand()%20;

        while(grid[row][col] != nullptr){
            row = rand()%20;
            col = rand()%20;
        }
        grid[row][col] = new Doodlebug;
    }
}

void Universe::display_grid(){
    for (int i = 0; i < GRID_SIZE; i++){
        for (int j = 0; j < GRID_SIZE; j++){
            if (grid[i][j] == nullptr){
                cout<<SPACE_CHAR<<" ";
            }
            else if(grid[i][j]->get_type() == ANT_TYPE){
                cout<<ANT_CHAR<<" ";
            }
            else{
                cout<<DOODLEBUG_CHAR<<" ";
            }        
        }
        cout<<endl;
    }
}

//Organism class implementation
Organism::Organism():row(-1), col(-1){}

int Organism::get_row() const{
    return row;
}

void Organism::set_row(int the_row){
    row = the_row;
}

int Organism::get_col() const{
    return col;
}

void Organism::set_col(int the_col){
    col = the_col;
}

void Organism::move(){
    cout<<"Org moved ";
}

//Ant class implementation
Ant::Ant():Organism(){}

void Ant::move(){
    cout<<"Ant moved ";
}

int Ant::get_type(){
    return ANT_TYPE;
}

//Doodlebug class implementation
Doodlebug::Doodlebug():Organism(){}

void Doodlebug::move(){
    cout<<"Dbug moved ";
}

int Doodlebug::get_type(){
    return DOODLEBUG_TYPE;
}
