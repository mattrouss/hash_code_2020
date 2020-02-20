#include <iostream>
#include <vector>

using namespace std;
using int_vec = vector<int>;

struct Library {
    int N;
    int T;
    int M;

    int_vec books;
};

istream& operator>>(istream &in, Library &l)
{
    in >> l.N >> l.T >> l.M;
    l.books.resize(l.N);
    for (auto &book: l.books)
        in >> book;

    return in;
}

ostream& operator<<(ostream &out, Library &l) {
    out << "Library {" << endl;
    out << "N: " << l.N << endl;
    out << "T: " << l.T << endl;
    out << "M: " << l.M << endl;
    out << "Books:" << endl;
    for (auto& book: l.books)
        out << book << " ";

    out << endl << "}" << endl;

    return out;
}

int B;
int L;
int D;

int_vec book_scores;
vector<Library> libraries;


int main() {
    cin >> B >> L >> D;
    book_scores.resize(B);
    for (auto &book_score: book_scores)
        cin >> book_score;

    libraries.resize(L);
    for (auto &l: libraries)
        cin >> l;

    cout << B << endl;
    cout << L << endl;
    cout << D << endl;
    cout << "Book scores:" << endl;
    for (auto &b: book_scores)
        cout << b << " ";
    cout << endl;
    cout << "Libraries:" << endl;
    for (auto &l: libraries)
        cout << l;

    return 0;
}
