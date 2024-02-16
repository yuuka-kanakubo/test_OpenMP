#include <iostream>
#include <time.h>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <omp.h>
using namespace std;


class reduction_example{

		private:
			int Nx=10;
			int Ny=50;
			int Nz=20;
			double fact=0.5;
			double b = 0.0;
			int ini_i = 0;
			int ini_j = 2;
			int ini_k = 4;


		public:
			reduction_example(){

			};
			~reduction_example(){};
			double take_sum2(){
				int i, j, k;
				double summation=0.;


				for (i=ini_i; i<=Nx; i++){
					for (j=ini_j; j<=Ny; j++){

						#pragma omp parallel
						{
							double summation_private=0.;

							#pragma omp for 
							for (k=ini_k; k<=Nz; k++){
								summation_private+=fact*4.0+b;
							}
							#pragma omp critical
							{
								summation+=summation_private;
							}
						}
					}
				}

				return summation;
			}

			double take_sum5_5(){
				int i, j, k;
				double summation=0.;


				#pragma omp parallel
				{
					double summation_private=0.;

					#pragma omp for collapse(3)
					for (i=ini_i; i<=Nx; i++){
						for (j=ini_j; j<=Ny; j++){
							for (k=ini_k; k<=Nz; k++){
								summation_private+=fact*4.0+b;
							}
						}
					}
					#pragma omp critical
					{
						summation+=summation_private;
					}
				}

				return summation;
			}

			double take_sum3_75(){
				int i, j, k;
				double summation=0.;


				for (i=ini_i; i<=Nx; i++){
					#pragma omp parallel
					{
						double summation_private=0.;

						#pragma omp for collapse(2)
						for (j=ini_j; j<=Ny; j++){
							for (k=ini_k; k<=Nz; k++){
								summation_private+=fact*4.0+b;
							}
						}
						#pragma omp critical
						{
							summation+=summation_private;
						}
					}
				}

				return summation;
			}

			double take_sum(){
				int i, j, k;
				double summation=0.0;

				for (i=ini_i; i<=Nx; i++){
					for (j=ini_j; j<=Ny; j++){
						#pragma omp parallel for reduction (+:summation)
						for (k=ini_k; k<=Nz; k++){
							summation+=fact*4.0+b;
						}
					}
				}


				return summation;
			}

			double take_sum3(){
				int i, j, k;
				double summation=0.0;

				for (i=ini_i; i<=Nx; i++){
					#pragma omp parallel for reduction (+:summation)
					for (j=ini_j; j<=Ny; j++){
						for (k=ini_k; k<=Nz; k++){
							summation+=fact*4.0+b;
						}
					}
				}


				return summation;
			}

			double take_sum3_5(){
				int i, j, k;
				double summation=0.0;

				for (i=ini_i; i<=Nx; i++){
					#pragma omp parallel for collapse(2) reduction (+:summation)
					for (j=ini_j; j<=Ny; j++){
						for (k=ini_k; k<=Nz; k++){
							summation+=fact*4.0+b;
						}
					}
				}


				return summation;
			}

			double take_sum4(){
				int i, j, k;
				double summation=0.0;

				#pragma omp parallel for reduction (+:summation)
				for (i=ini_i; i<=Nx; i++){
					for (j=ini_j; j<=Ny; j++){
						for (k=ini_k; k<=Nz; k++){
							summation+=fact*4.0+b;
						}
					}
				}


				return summation;
			}

			double take_sum5(){
				int i, j, k;
				double summation=0.0;

				#pragma omp parallel for collapse(3) reduction (+:summation)
				for (i=ini_i; i<=Nx; i++){
					for (j=ini_j; j<=Ny; j++){
						for (k=ini_k; k<=Nz; k++){
							summation+=fact*4.0+b;
						}
					}
				}


				return summation;
			}

			double take_sum_noparallel(){
				int i, j, k;
				double summation=0.0;

				for (i=ini_i; i<=Nx; i++){
					for (j=ini_j; j<=Ny; j++){
						for (k=ini_k; k<=Nz; k++){
							summation+=fact*4.0+b;
						}
					}
				}

				return summation;
			}

	};
