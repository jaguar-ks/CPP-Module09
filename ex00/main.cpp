/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 04:21:48 by faksouss          #+#    #+#             */
/*   Updated: 2023/11/18 04:38:06 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"
#include <fstream>
#include <iostream>

std::map<Time, float> &readDataFile( std::ifstream &file ){
    std::map<Time, float> *Data;
    return *Data;
}

int main(int ac, char **av){
    if (ac == 2){
        std::ifstream dataBase("data.csv");
        std::ifstream exChange(av[1]);
        if (!dataBase.is_open() || !exChange.is_open()){
            std::cerr << "Error : Can't open one of the files" << std::endl;
            return 1;
        }
        std::map<Time, float> Data = readDataFile(dataBase);
        std::map<Time, float> ExFl = readDataFile(exChange);
    }
    else{
        std::cerr << "Error : "; 
        ac == 1? std::cerr << "No argument given" << std::endl : std::cerr << "To many arguments" << std::endl;
        return 1;
    }
}
