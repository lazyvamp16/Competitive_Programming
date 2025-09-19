class Spreadsheet {
public:
    vector<vector<int>> sheet;
    Spreadsheet(int rows) {
        sheet = vector<vector<int>>(27,vector<int>(rows+1,0));
    }
    
    void setCell(string cell, int value) {
        int column = cell[0]-'A';
        int row = stoi(cell.substr(1));
        sheet[column][row] = value;
    }
    
    void resetCell(string cell) {
        int column = cell[0]-'A';
        int row = stoi(cell.substr(1));
        sheet[column][row]=0;
    }
    
    int getValue(string formula) {
        int index;
        int sum=0;
        for(int i=1; i<formula.size(); i++){
            if(formula[i]=='+') index = i;
        }
        if(formula[1]>='A'){
            int column = formula[1]-'A';
            int row = stoi(formula.substr(2,index-2));
            sum += sheet[column][row];
        }
        else{
            sum += stoi(formula.substr(1,index-1));
        }
        
        if(formula[index+1]>='A'){
            int column = formula[index+1]-'A';
            int row = stoi(formula.substr(index+2));
            sum += sheet[column][row];
        }
        else{
            sum += stoi(formula.substr(index+1));
        }
        return sum;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */