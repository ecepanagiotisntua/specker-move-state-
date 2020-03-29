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
