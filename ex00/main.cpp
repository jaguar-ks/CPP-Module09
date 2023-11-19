/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 04:21:48 by faksouss          #+#    #+#             */
/*   Updated: 2023/11/19 12:42:34 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"
#include <cstdlib>
#include <exception>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>

std::pair<Time, float> getDataPair( std::string &line ){
    try {
        std::string t[4];
        t[0].assign(line,0,4);
        t[1].assign(line,5,2);
        t[2].assign(line,8,2);
        t[3].assign(line,11,line.size()-11);
        Time tm(atoi(t[0].c_str()), atoi(t[1].c_str()), atoi(t[2].c_str()));
        float val = atof(t[3].c_str());
        if (val < 0)
            throw std::out_of_range("Error : NegativeValue found");
        std::pair<Time, float> pr(tm,val);
        return pr;
    }
    catch (std::exception &e){
        std::cerr << "Corapted DataBase " << e.what() << std::endl;
        exit(1);
    }
}

MAP readDataFile( std::ifstream &file ){
    MAP Data;
    std::string line;

    while (!std::getline(file, line).eof()){
        if (line == "date,exchange_rate"){
            if (std::getline(file, line).eof()){
                std::cerr << "Error : Empty file" << std::endl;
                exit(1);
            }
            continue;
        }
        Data.insert(getDataPair(line));
    }
    file.close();
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
        MAP Data = readDataFile(dataBase);
        BitcoinExchange ex(Data);
        ex.exchangeBitcoin(exChange);
    }
    else{
        std::cerr << "Error : "; 
        ac == 1? std::cerr << "No argument given" << std::endl : std::cerr << "To many arguments" << std::endl;
        return 1;
    }
}
