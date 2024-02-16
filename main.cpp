#include "reduction_example.h"

int main()
{

        #pragma omp parallel 
	{
		int t = omp_get_thread_num();
		//cout << "Hello world" << t << endl;
		//stringstream ss;
                //ss << "Hello world " << t << endl;
		//cerr << ss.str() << endl; 
	}


        reduction_example re;


	std::chrono::system_clock::time_point  start, end; 

	start = std::chrono::system_clock::now();
        cout << "1)Reduction : " << scientific << setprecision(15) << re.take_sum() << endl;
	end = std::chrono::system_clock::now();
	double elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
	cout << setw(16) << elapsed << " ms "<< endl;
	cout << endl;

	start = std::chrono::system_clock::now();
        cout << "2)Reduction manual: " << scientific<< setprecision(15)<< re.take_sum2() << endl;
	end = std::chrono::system_clock::now();
	double elapsed2 = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
	cout << setw(16) << elapsed2  << " ms "<< endl;
	cout << endl;

	start = std::chrono::system_clock::now();
        cout << "3)Reduction for 2inner loops: " << scientific<< setprecision(15)<< re.take_sum3() << endl;
	end = std::chrono::system_clock::now();
	double elapsed3 = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
	cout << setw(16) << elapsed3 << " ms " << endl;
	cout << endl;

	start = std::chrono::system_clock::now();
        cout << "3.5)Reduction for 2inner loops with collapse : " << scientific<< setprecision(15)<< re.take_sum3_5() << endl;
	end = std::chrono::system_clock::now();
	double elapsed3_5 = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
	cout << setw(16) << elapsed3_5 << " ms " << endl;
	cout << endl;

	start = std::chrono::system_clock::now();
        cout << "3.75)Reduction for 2inner loops with collapse manual : " << scientific<< setprecision(15)<< re.take_sum3_75() << endl;
	end = std::chrono::system_clock::now();
	double elapsed3_75 = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
	cout << setw(16) << elapsed3_75 << " ms " << endl;
	cout << endl;

	start = std::chrono::system_clock::now();
        cout << "4)Reduction for 3 loops: " << scientific<< setprecision(15)<< re.take_sum4() << endl;
	end = std::chrono::system_clock::now();
	double elapsed4 = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
	cout << setw(16) << elapsed4 << " ms " << endl;
	cout << endl;

	start = std::chrono::system_clock::now();
        cout << "5)Reduction for 3 loops with collapse(3): " << scientific<< setprecision(15)<< re.take_sum5() << endl;
	end = std::chrono::system_clock::now();
	double elapsed5 = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
	cout << setw(16) << elapsed5 << " ms " << endl;
	cout << endl;

	start = std::chrono::system_clock::now();
        cout << "5.5)Reduction for 3 loops with collapse(3) manual: " << scientific<< setprecision(15)<< re.take_sum5_5() << endl;
	end = std::chrono::system_clock::now();
	double elapsed5_5 = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
	cout << setw(16) << elapsed5_5 << " ms " << endl;
	cout << endl;

	start = std::chrono::system_clock::now();
        cout << "6)no parallelisation: " << scientific<< setprecision(15)<< re.take_sum_noparallel() << endl;
	end = std::chrono::system_clock::now();
	double elapsed6 = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
	cout << setw(16) << elapsed6 << " ms " << endl;

return 0;
}
