/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 03:25:33 by faksouss          #+#    #+#             */
/*   Updated: 2023/11/20 04:25:41 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"
#include <_ctype.h>
#include <algorithm>
#include <exception>
#include <fstream>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>

/*     [Overload Of the insertion Operator(<<)]      */
std::ostream &operator<<( std::ostream &out, Time const &t) {
    out << t.y << '-';
    t.m < 10? out << '0' << t.m : out << t.m;
    t.d < 10? out << '-' << '0' << t.d : out << '-' << t.d;
    return out;
}
/*****************************************************/

/*******************************[BITCOINEXCHANGE]************************************/
/*[BitcoinExchange Constructors and Deconstrucot]*/
BitcoinExchange::BitcoinExchange( void ){}

BitcoinExchange::~BitcoinExchange( void ){}

BitcoinExchange::BitcoinExchange( MAP &dataBase ) : dataBase(dataBase) {}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &obj ){*this = obj;}
/**************************************************/

/*         [(=) Operator Overload]         */
BitcoinExchange &BitcoinExchange::operator=( const BitcoinExchange &obj ){
    if (this != &obj)
        this->dataBase = obj.getDataBase();
    return *this;
}
/*******************************************/

/*        [Geters & Seters]        */
MAP BitcoinExchange::getDataBase( void ) const{return this->dataBase;}

void BitcoinExchange::setDataBase( MAP &dataBase ){this->dataBase = dataBase;}
/***********************************/

/*     [Reading & Exchanging Bitcoin Value]    */
/*
    Helper function to parss the line checking if the format is valid
    and filling the needed data to work with and returning true otherwise
    returns false and printing an error discribing what happend
*/
bool checkLine(std::string &line, std::string *d, std::string &v, int c){
    if (line.find('|') != std::string::npos && line.find('|',line.find('|')+1) == std::string::npos){
        std::string f[2];
        int p = 0;
        for(size_t i = 0; i < line.size(); i++){
            p+=(line[i] == '|');
            if (line[i] == '|')
                continue;
            f[p] += line[i];
        }
        f[0].erase(f[0].find_last_not_of(" \t\v\t\f\r")+1);
        f[1].erase(f[1].find_last_not_of(" \t\v\t\f\r")+1);
        f[1].erase(0,f[1].find_first_not_of(" \t\v\t\f\r"));
        if (!c){
            if(f[0] != "date" || f[1] != "value"){
                std::cerr << "Error : Invalid begging of input file" << std::endl;
                return false;
            }
            return true;
        }
        p = 0;
        for (size_t i = 0; i < f[0].size(); i++){
            p+=(f[0][i] == '-');
            if (p>2){
                std::cerr << "Error : Invalid date format => " << f[0] << std::endl;
                return false;
            }
            if (f[0][i] == '-')
                continue;
            else if (!isdigit(f[0][i])){
                std::cerr << "Error : Invalid date format => " << f[0] << std::endl;
                return false;
            }
            d[p] += f[0][i];
        }
        p=0;
        for (size_t i = 0; i < f[1].size(); i++){
            p+=(f[1][i] == '.');
            if (p>1 || (!isdigit(f[1][i]) && f[1][i] != '.')){
                std::cerr << "Error : Invalid value => " << f[1] << std::endl;
                return false;
            }
            v += f[1][i];
        }
        return true;
    }
    std::cerr << "Error : Not following the format rules [date | value] =>" << line << std::endl;
    return false;
}

void BitcoinExchange::exchangeBitcoin( std::ifstream &input ){
    std::string line, d[3], v;
    int c=0;

    while (!std::getline(input, line).eof()){
        line.erase(0, line.find_first_not_of(" \t\v\f\r"));
        line.erase(line.find_last_not_of(" \t\v\f\r") + 1);
        for(int i = 0; i < 3; i++)
            d[i].clear();
        v.clear();
        if (line.empty())
            continue;
        if(!checkLine(line, d, v, c) || !c){
            c++;
            continue;
        }
        try{
            const Time t(atoi(d[0].c_str()), atoi(d[1].c_str()), atoi(d[2].c_str()));
            float val = atof(v.c_str());
            if (val > 1000 || val < 0)
                throw std::out_of_range("Error : Out of range value");
            std::map<Time, float>::iterator it = this->dataBase.find(t);
            if (it != this->dataBase.end())
                std::cout << it->first << " => " << val << " = " << it->second * val << std::endl;
            else{
                it = this->dataBase.lower_bound(t);
                if (it != this->dataBase.begin())
                    it--;
                std::cout << t << " => " << val << " = " << it->second * val << std::endl;
            }
        }
        catch(std::exception &e){
            int y = atoi(d[0].c_str()), m = atoi(d[1].c_str()), j = atoi(d[2].c_str());
            std::cerr << e.what();
            if (((y>2023 || y<2008)||(m>12 || m<1)|| j<1)||(m<=7 && j>30+(m%2!=0))||(m>=8 && j>30+(m%2==0))||(m==2 && j>28+(y%4==0)))
                std::cerr << " => " << d[0] << ' ' << d[1] << ' ' << d[2] << std::endl;
            else
                std::cerr << " => " << v << std::endl;
        }
        c++;
    }
    if (!c)
        std::cerr << "Error : You used an empty file" << std::endl;
    input.close();
}
/***********************************************/
/************************************************************************************/


/*************************************[TIME]*****************************************/
/*         [Time Constructors]         */
Time::Time(unsigned int y, unsigned int m, unsigned d){
    if (((y>2023 || y<2008)||(m>12 || m<1)|| d < 1)||((m<=7 && d>30+(m%2!=0))||(m>=8 && d>30+(m%2==0))||(m==2 && d > 28+(y%4==0))))
        throw timeError();
    this->d = d;
    this->m = m;
    this->y = y;
}

Time::Time( void ){}
/*************************************/

/*         [(=) Operator Overload]         */
Time &Time::operator=( const Time &date ){
    if (this != &date){this->d=date.d; this->m=date.m; this->y=date.y;}
    return *this;
}
/*******************************************/

/*         [Comperation Operators Overload]         */
bool Time::operator>( const Time &a ) const {
    return (this->y>a.y) || (this->y==a.y && this->m>a.m) || (this->y==a.y && this->m==a.m && this->d>a.d);
}

bool Time::operator<( const Time &a ) const {
    return (this->y<a.y) || (this->y==a.y && this->m<a.m) || (this->y==a.y && this->m==a.m && this->d<a.d);
}

bool Time::operator>=( const Time &a ) const {
    return (this->y>=a.y) || (this->y==a.y && this->m>=a.m) || (this->y==a.y && this->m==a.m && this->d>=a.d);
}

bool Time::operator<=( const Time &a ) const {
    return (this->y<=a.y) || (this->y==a.y && this->m<=a.m) || (this->y==a.y && this->m==a.m && this->d<=a.d);
}

bool Time::operator==( const Time &a ) const {
    return this->y == a.y && this->m == a.m && this->d == a.d;
}

bool Time::operator!=( const Time &a ) const {
    return !(this->y == a.y && this->m == a.m && this->d == a.d);
}
/**************************************************/

/*         [Time Out Of Range Error]         */
const char *Time::timeError::what() const throw(){return "Error : Incorect date";}
/*********************************************/
/************************************************************************************/

