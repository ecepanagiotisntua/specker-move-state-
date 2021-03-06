#include <stdexcept>  
#include <iostream>  
  
using namespace std;  
  
class Move {  
  
int sourceh;  
int sourcec;  
int targeth;  
int targetc;  
  
public:  
// Take sc coins from heap sh and put tc coins to heap th.  
Move(int sh, int sc, int th, int tc);  
  
int getSource() const;  
int getSourceCoins() const;  
int getTarget() const;  
int getTargetCoins() const;  
  
friend ostream & operator << (ostream &out, const Move &move);  
};  
  
Move::Move(int sh, int sc, int th, int tc){  
sourceh = sh;  
sourcec = sc;  
targeth = th;  
targetc = tc;  
}  
  
int Move::getSource() const {  
return sourceh;  
}  
  
int Move::getSourceCoins() const {  
return sourcec;  
}  
  
int Move::getTarget() const {  
return targeth;  
}  
  
int Move::getTargetCoins() const {  
return targetc;  
}  
  
ostream & operator << (ostream &out, const Move &move){  
if (move.getTargetCoins() > 0)  
out << "takes " << move.getSourceCoins() << " coins from heap " << move.getSource() << " and puts " << move.getTargetCoins() << " coins to heap " << move.getTarget();  
else  
out << "takes " << move.getSourceCoins() << " coins from heap " << move.getSource() << " and puts nothing";  
return out;  
}  
  
