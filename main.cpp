#include <iostream>
#include <vector>

using namespace std;
using int_vec = vector<int>;


int library_id_count = 0;
struct Library {
    int id;
    int N;
    int T;
    int M;

    int_vec books;
};

istream& operator>>(istream &in, Library &l)
{
    l.id = library_id_count++;
    in >> l.N >> l.T >> l.M;
    l.books.resize(l.N);
    for (auto &book: l.books)
        in >> book;

    return in;
}

ostream& operator<<(ostream &out, Library &l) {
    out << "Library #" << l.id << " {" << endl;
    out << "N: " << l.N << endl;
    out << "T: " << l.T << endl;
    out << "M: " << l.M << endl;
    out << "Books:" << endl;
    for (auto& book: l.books)
        out << book << " ";

    out << endl << "}" << endl;

    return out;
}

struct Output {
    vector<Library> libraries;
    vector<int_vec> books;


    void add_library(const Library &l, const int_vec &books);
    void dump() const;
};

void Output::add_library(const Library &l, const int_vec &b) {
    libraries.push_back(l);
    books.push_back(b);
}

void Output::dump() const {
    cout << libraries.size() << endl;
    for (auto i = 0u; i < libraries.size(); i++)
    {
        cout << libraries[i].id << " " << books[i].size() << endl;
        for (auto &b: books[i])
            cout << b << " ";
        cout << endl;
    }
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

    Output o;
    o.add_library(libraries[0], libraries[0].books);
    o.add_library(libraries[1], libraries[1].books);
    o.dump();

    return 0;
}
