template <class Choose, class Unchoose, class Done>
void backtrack(int depth, int target_depth, Choose choose, Unchoose unchoose, Done done) {
    if (depth == target_depth) {
        done();
        return;
    }
    // user: iterate choices here, call choose(choice), recurse, then unchoose(choice)
}
