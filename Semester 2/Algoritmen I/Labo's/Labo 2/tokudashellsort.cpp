


template<class T>
class TokudaShellSort: public ShellSort<T> {
	void operator()(std::vector<T> & v) const {
		int Tokudainc[] = {1, 4, 9, 20, 46, 103, 233, 525, 1182, 2660, 5985, 13467, 30301, 68178, 153401, 345152, 776591, 1747331, 3931496, 8845866, 19903198, 44782196, 100759940, 226709866, 510097200, 1147718700};
		shell_sort(v, Tokudainc, 26);
	}
	
	string get_name() const{
		return "Tokuda Shell Sort";
	}
};
