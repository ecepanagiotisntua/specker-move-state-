#include <stdexcept>

class State {  
  
int heaps;  
int *coins;  
  
public:  
// State with h heaps, where the i-th heap starts with c[i] coins.  
State(int h, const int c[]);  
~State();  
  
void next(const Move &move) throw(logic_error);  
bool winning() const;  
  
int getHeaps() const;  
int getCoins(int h) const throw(logic_error);  
  
friend ostream & operator << (ostream &out, const State &state);  
};  
  
State::State(int h, const int c[]){  
  heaps = h;  
  coins = new int[heaps];  
    for (int i = 0; i < heaps; i++)  
      coins[i] = c[i];  
}  
  
State::~State(){  
  delete [] coins;  
  return;  
}  
  
void State::next(const Move &move) throw (logic_error){  
  if (move.getSource() < 0 || move.getSource() >= heaps) throw logic_error("invalid heap");  
  if (move.getTarget() < 0 || move.getTarget() >= heaps) throw logic_error("invalid heap");  
  if (move.getSourceCoins() > coins[move.getSource()] || move.getSourceCoins() < 0 || move.getTargetCoins() < 0 || move.getTargetCoins() >= move.getSourceCoins()) throw logic_error ("invalid heap");  
  coins[move.getSource()] -= move.getSourceCoins();  
  coins[move.getTarget()] += move.getTargetCoins();  
}  
  
bool State::winning() const{  
  bool flag = true;  
  for (int i = 0; i < heaps; i++){  
    if (coins[i] != 0) {flag = false;  
    break;  
    }  
  }  
  return flag;  
}  
  
int State::getHeaps() const{  
  return heaps;  
}  
  
int State::getCoins(int h) const throw(logic_error){  
  if (h < 0 || h >= heaps) throw logic_error("invalid heap");  
  return coins[h];  
}  
  
ostream & operator << (ostream &out, const State &state){  
  out << state.coins[0];  
  for (int i = 1; i < state.heaps; i++){  
    out << ", " << state.getCoins(i);  
  }  
  return out;  
}  
