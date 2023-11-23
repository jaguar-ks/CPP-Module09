/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:33:20 by faksouss          #+#    #+#             */
/*   Updated: 2023/11/23 09:47:19 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PmergeMe.hpp"
#include <ctime>
#include <exception>
#include <vector>

int main(int ac, char **av){
    if (ac >= 3){
        try{
            double a = clock();
            std::vector<int> lol = PmergeMe<std::vector<int> >(ac, av);
            a = (clock()-a)/CLOCKS_PER_SEC;
            double b = clock();
            PmergeMe<std::deque<int> >(ac, av);
            b = (clock()-b)/CLOCKS_PER_SEC;
            std::cout << "Before: ";
            for (int i = 1; i < ac; i++)
                std::cout << av[i] << " ";
            std::cout << std::endl << "After : ";
            for (size_t i = 0; i < lol.size(); i++)
                std::cout << lol[i] << " ";
            std::cout << std::endl << std::endl << "Time spent sorting " << ac - 1 << " using [Vector] is: " << std::fixed << a;
            std::cout << std::endl << "Time spent sorting " << ac - 1 << " using [Deque] is: " << std::fixed << b << std::endl;
        }
        catch(std::exception &e){
            std::cout << e.what() << std::endl;
            return 1;
        }
    }
    else{
        std::cout << "Error : Not enough arguments" << std::endl;
        return 1;
    }
}
