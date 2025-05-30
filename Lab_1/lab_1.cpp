//Pember, Kevin

//Part 1
map<std::string, std::set<std::string>> neighbors = {
   
   {"North Dakota", {"Minnesota", "South Dakota"}},
   {"Illinois", {"Indiana", "Iowa", "Michigan", "Missouri", "Wisconsin"}},
   {"Minnesota", {"North Dakota", "South Dakota", "Iowa", "Wisconsin", "Michigan"}},
   {"South Dakota", {"North Dakota", "Minnesota", "Iowa", "Nebraska"}},
   {"Nebraska", {"South Dakota", "Kansas", "Iowa", "Missouri"}},
   {"Kansas", {"Nebraska", "Missouri"}},
   {"Iowa", {"Minnesota", "South Dakota", "Nebraska", "Missouri","Illinois", "Wisconsin"}},
   {"Missouri", {"Kansas", "Nebraska", "Iowa","Illinois"}},
   {"Wisconsin", {"Minnesota","Iowa","Illinois", "Michigan"}},
   {"Indiana", {"Michigan","Ohio","Illinois"}},
   {"Ohio", {"Indiana","Michigan"}},
   {"Michigan", {"Minnesota","Ohio","Illinois", "Indiana", "Wisconsin"}},
};

//Part 2
void printNeighbors (const map<std::string, std::set<std::string>>& neighbors) {
   for(auto [key, value] : neighbors){
      cout << key << " borders with: ";
      for(auto x : value){
         cout << x << " ";
      }
      cout << endl;
   }
}

//Part 3
vector< vector<int>> neighbors = {
   {0,1,1,0,1,0,1,0,0,0,0,1},
   {1,0,0,0,1,0,0,0,0,1,0,0},
   {1,0,0,0,0,1,1,1,0,0,1,1},
   {0,0,0,0,0,0,1,1,0,0,0,0},
   {1,1,0,0,0,1,0,0,0,1,0,1},
   {0,0,1,0,1,0,0,0,1,0,1,1},
   {1,0,1,1,0,0,0,1,0,0,0,0},
   {0,0,1,1,0,0,1,0,0,0,1,0},
   {0,0,0,0,0,1,0,0,0,0,1,0},
   {0,1,0,0,1,0,0,0,0,0,0,0},
   {0,0,1,0,0,1,0,1,1,0,0,0},
   {1,0,1,0,1,1,0,0,0,0,0,0}
};

//Part 4
bool areNeighbors(const vector<string>& states, const vector<vector<int>>& connections, const string& state1, const string& state2) {
   int first = 0;
   while (states[first] != state1){
      first++;
   }
   int second = 0;
   while (states[second] != state2){
      second++;
   }
   int neighbors = connections[first][second];
   if(neighbors == 1){
      return true;
   }else{
      return false;
   }
}
