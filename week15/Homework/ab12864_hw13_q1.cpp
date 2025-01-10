#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <typeinfo>

using namespace std;

const int GRID_SIZE = 20;

//character denotation
const char ANT_CHAR = 'o';
const char DOODLEBUG_CHAR = 'X';
const char SPACE_CHAR = '-';

//start number of critters
const int START_ANTS = 100, START_DOODLEBUGS = 5;

//moves to breed
const int ANT_BREED_MOVE = 3, DOODLEBUG_BREED_MOVE = 8;

//moves to starve - doodlebug
const int DOODLEBUG_STARVE_MOVE = 3;

//ints for ant and doodlebug
const int ANT_TYPE = 1;
const int DOODLEBUG_TYPE = 2;

//ints for move direction
const int DEATH = -1;
const int UNCHANGED = 0;
const int UP = 1;
const int DOWN = 2;
const int LEFT = 3;
const int RIGHT = 4;

class Universe;

//class Organism
class Organism{
    public:
        Organism();
        Organism(int initial_row, int initial_col);
        int get_row() const;
        void set_row(int the_row);
        int get_col() const;
        void set_col(int the_col);
        virtual void move(Universe& the_universe, int direction) = 0;
        virtual int get_type() = 0;
    private:
        int row;
        int col;
};

class Universe{
    public:
        Universe();
        void initialize_universe();
        void simulate_time_step();
        int find_move_direction(int row, int col);
        void display_grid();
        Organism* get_grid();
    private:
        Organism* grid[GRID_SIZE][GRID_SIZE];
        int num_of_timesteps;
    friend class Doodlebug;
    friend class Ant;

};

class Ant: public Organism{
    public:
        Ant();
        Ant(int initial_row, int initial_col);
        virtual void move(Universe& the_universe, int direction);
        void breed();
        virtual int get_type();
};

class Doodlebug: public Organism{
    public:
        Doodlebug();
        Doodlebug(int initial_row, int initial_col);
        virtual void move(Universe& the_universe, int direction);
        void eat();
        void breed();
        virtual int get_type();
        int get_starve_counter();
        void set_starve_counter(int current_count);
    private:
        int starve_counter;
};

int main(){

    Universe uni1;
    uni1.initialize_universe();
    uni1.display_grid();
    uni1.simulate_time_step();
    cout<<endl;
    uni1.display_grid();

    //Ant ant1(4,6);
    //cout<<ant1.get_row()<<endl;

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
        grid[row][col] = new Ant(row, col);
    }

    for (int i = 0; i < START_DOODLEBUGS; i++){

        int row = rand()%20;
        int col = rand()%20;

        while(grid[row][col] != nullptr){
            row = rand()%20;
            col = rand()%20;
        }
        grid[row][col] = new Doodlebug(row, col);
    }
}

void Universe::simulate_time_step(){
    for (int i = 0; i < GRID_SIZE; i++){
        for (int j = 0; j < GRID_SIZE; j++){
            if ((grid[i][j] != nullptr) && (grid[i][j]->get_type() == DOODLEBUG_TYPE)){
                int direction = find_move_direction(i,j);
                Doodlebug* doodlebug = dynamic_cast<Doodlebug*>(grid[i][j]);
                doodlebug -> move(*this, direction);
            }
        }
    }
    for (int i = 0; i < GRID_SIZE; i++){
        for (int j = 0; j < GRID_SIZE; j++){
            if ((grid[i][j] != nullptr) && (grid[i][j]->get_type() == ANT_TYPE)){
                int direction = find_move_direction(i,j);
                Ant* ant = dynamic_cast<Ant*>(grid[i][j]);
                ant -> move(*this, direction);
            }
        }
    }
}

int Universe::find_move_direction(int row, int col){
    
    vector <int> viable_positions;
    srand(time(0));

    if (grid[row][col]->get_type() == ANT_TYPE){
        
        if ((col > 0) && (grid[row][col-1] == nullptr)){
            viable_positions.push_back(LEFT);
        }
        if ((col < GRID_SIZE-1) && (grid[row][col+1] == nullptr)){
            viable_positions.push_back(RIGHT);
        }
        if ((row > 0) && (grid[row-1][col] == nullptr)){
            viable_positions.push_back(UP);
        }
        if ((row < GRID_SIZE-1) && (grid[row+1][col] == nullptr)){
            viable_positions.push_back(DOWN);
        }
    }

    else if (grid[row][col]->get_type() == DOODLEBUG_TYPE){
        if ((col > 0) && (grid[row][col-1] != nullptr) && (grid[row][col-1]->get_type() == ANT_TYPE)){
            viable_positions.push_back(LEFT);
        }
        if ((col < GRID_SIZE-1) && (grid[row][col+1] != nullptr) && (grid[row][col+1]->get_type() == ANT_TYPE)){
            viable_positions.push_back(RIGHT);
        }
        if ((row > 0) && (grid[row-1][col] != nullptr) && (grid[row-1][col]->get_type() == ANT_TYPE)){
            viable_positions.push_back(UP);
        }
        if ((row < GRID_SIZE-1) && (grid[row+1][col] != nullptr) && (grid[row+1][col]->get_type() == ANT_TYPE)){
            viable_positions.push_back(DOWN);
        }

        Doodlebug* doodlebug = dynamic_cast<Doodlebug*>(grid[row][col]);

        if (viable_positions.empty()){
            if (doodlebug->get_starve_counter() == 3){
                return DEATH;
            }
            if ((col > 0) && (grid[row][col-1] == nullptr)){
            viable_positions.push_back(LEFT);
            }
            if ((col < GRID_SIZE-1) && (grid[row][col+1] == nullptr)){
                viable_positions.push_back(RIGHT);
            }
            if ((row > 0) && (grid[row-1][col] == nullptr)){
                viable_positions.push_back(UP);
            }
            if ((row < GRID_SIZE-1) && (grid[row+1][col] == nullptr)){
                viable_positions.push_back(DOWN);
            }
        }
    }

    if (viable_positions.empty()){
        return UNCHANGED;
    }
    else{
        return viable_positions[rand()%viable_positions.size()];
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

Organism::Organism(int initial_row, int initial_col):row(initial_row), col(initial_col){}

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

//Ant class implementation
Ant::Ant():Organism(){}

Ant::Ant(int initial_row, int initial_col): Organism(initial_row, initial_col){}

void Ant::move(Universe& the_universe, int direction){

    int i = get_row();
    int j = get_col();

    if (direction == 1){
        the_universe.grid[i-1][j] = the_universe.grid[i][j];
        the_universe.grid[i-1][j]->set_row(i-1);
        the_universe.grid[i][j] = nullptr;
    }
    else if (direction == 2){
        the_universe.grid[i+1][j] = the_universe.grid[i][j];
        the_universe.grid[i+1][j]->set_row(i+1);
        the_universe.grid[i][j] = nullptr;
    }
    else if (direction == 3){
        the_universe.grid[i][j-1] = the_universe.grid[i][j];
        the_universe.grid[i][j-1]->set_col(j-1);
        the_universe.grid[i][j] = nullptr;
    }
    else if (direction == 4){
        the_universe.grid[i][j+1] = the_universe.grid[i][j];
        the_universe.grid[i][j+1]->set_col(j+1);
        the_universe.grid[i][j] = nullptr;
    }
}

int Ant::get_type(){
    return ANT_TYPE;
}

//Doodlebug class implementation
Doodlebug::Doodlebug():Organism(){}

Doodlebug::Doodlebug(int initial_row, int initial_col): Organism(initial_row, initial_col){}

void Doodlebug::move(Universe& the_universe, int direction){

    int i = get_row();
    int j = get_col();


    if (direction == 1){
        if (the_universe.grid[i-1][j] == nullptr){
            the_universe.grid[i-1][j] = the_universe.grid[i][j];
            the_universe.grid[i-1][j]->set_row(i-1);
            the_universe.grid[i][j] = nullptr;
            Doodlebug* doodlebug = dynamic_cast<Doodlebug*>(the_universe.grid[i-1][j]);
            doodlebug->set_starve_counter(doodlebug->get_starve_counter()+1);
        }
        else{
            the_universe.grid[i-1][j] = nullptr;
            the_universe.grid[i-1][j] = the_universe.grid[i][j];
            the_universe.grid[i-1][j]->set_row(i-1);
            the_universe.grid[i][j] = nullptr;
            Doodlebug* doodlebug = dynamic_cast<Doodlebug*>(the_universe.grid[i-1][j]);
            doodlebug->set_starve_counter(0);
        }
    }
    else if (direction == 2){
        if (the_universe.grid[i+1][j] == nullptr){
            the_universe.grid[i+1][j] = the_universe.grid[i][j];
            the_universe.grid[i+1][j]->set_row(i+1);
            the_universe.grid[i][j] = nullptr;
            Doodlebug* doodlebug = dynamic_cast<Doodlebug*>(the_universe.grid[i+1][j]);
            doodlebug->set_starve_counter(doodlebug->get_starve_counter()+1);
        }
        else{
            the_universe.grid[i+1][j] = nullptr;
            the_universe.grid[i+1][j] = the_universe.grid[i][j];
            the_universe.grid[i+1][j]->set_row(i+1);
            the_universe.grid[i][j] = nullptr;
            Doodlebug* doodlebug = dynamic_cast<Doodlebug*>(the_universe.grid[i+1][j]);
            doodlebug->set_starve_counter(0);
        }
    }
    else if (direction == 3){
        if (the_universe.grid[i][j-1] == nullptr){
            the_universe.grid[i][j-1] = the_universe.grid[i][j];
            the_universe.grid[i][j-1]->set_col(j-1);
            the_universe.grid[i][j] = nullptr;
            Doodlebug* doodlebug = dynamic_cast<Doodlebug*>(the_universe.grid[i][j-1]);
            doodlebug->set_starve_counter(doodlebug->get_starve_counter()+1);
        }
        else{
            the_universe.grid[i][j-1] = nullptr;
            the_universe.grid[i][j-1] = the_universe.grid[i][j];
            the_universe.grid[i][j-1]->set_col(j-1);
            the_universe.grid[i][j] = nullptr;
            Doodlebug* doodlebug = dynamic_cast<Doodlebug*>(the_universe.grid[i][j-1]);
            doodlebug->set_starve_counter(0);
        }
    }
    else if (direction == 4){
        if (the_universe.grid[i][j+1] == nullptr){
            the_universe.grid[i][j+1] = the_universe.grid[i][j];
            the_universe.grid[i][j+1]->set_col(j+1);
            the_universe.grid[i][j] = nullptr;
            Doodlebug* doodlebug = dynamic_cast<Doodlebug*>(the_universe.grid[i][j+1]);
            doodlebug->set_starve_counter(doodlebug->get_starve_counter()+1);
        }
        else{
            the_universe.grid[i][j+1] = nullptr;
            the_universe.grid[i][j+1] = the_universe.grid[i][j];
            the_universe.grid[i][j+1]->set_col(j+1);
            the_universe.grid[i][j] = nullptr;
            Doodlebug* doodlebug = dynamic_cast<Doodlebug*>(the_universe.grid[i][j+1]);
            doodlebug->set_starve_counter(0);
        }
    }
}

int Doodlebug::get_type(){
    return DOODLEBUG_TYPE;
}

int Doodlebug::get_starve_counter(){
    return starve_counter;
}

void Doodlebug::set_starve_counter(int current_count){
    starve_counter= current_count;
}