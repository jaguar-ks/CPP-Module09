/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 04:21:48 by faksouss          #+#    #+#             */
/*   Updated: 2023/11/18 05:50:12 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <utility>

std::string *takeTimeAndVal( std::string &line ){
    std::string t[4];
} 

std::pair<Time, float> DataFile( std::string &line ){
    std::pair<Time, float> pr;
    float val = 0;
    Time tm;
    std::string t[4] = takeTimeAndVal(line);
    return pr;
}

std::pair<Time, float> ExCahngeFile( std::string &line ){
    std::pair<Time, float> r;
    return r;
}

std::map<Time, float> readDataFile( std::ifstream &file, int flg ){
    std::map<Time, float> Data;
    std::string line;
    std::pair<Time, float> (*f[2])(std::string &str) = {&DataFile, &ExCahngeFile};

    while (!std::getline(file, line).eof()){
        if (line == "date,exchange_rate" || line == "date | value"){
            if (std::getline(file, line).eof()){
                std::cerr << "Error : Empty file" << std::endl;
                exit(1);
            }
        }
        Data.insert(f[flg](line));
    }
    return Data;
}

int main(int ac, char **av){
    if (ac == 2){
        std::ifstream dataBase("data.csv");
        std::ifstream exChange(av[1]);
        if (!dataBase.is_open() || !exChange.is_open()){
            std::cerr << "Error : Can't open one of the files" << std::endl;
            return 1;
        }
        std::map<Time, float> Data = readDataFile(dataBase, 0);
        std::map<Time, float> ExFl = readDataFile(exChange, 1);
    }
    else{
        std::cerr << "Error : "; 
        ac == 1? std::cerr << "No argument given" << std::endl : std::cerr << "To many arguments" << std::endl;
        return 1;
    }
}
