/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 03:25:33 by faksouss          #+#    #+#             */
/*   Updated: 2023/11/19 03:46:51 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"

/*[BitcoinExchange Constructors and Deconstrucot]*/
BitcoinExchange::BitcoinExchange( void ){}

BitcoinExchange::~BitcoinExchange( void ){}

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
std::map<Time, float> BitcoinExchange::getDataBase( void ) const{return this->dataBase;}

void BitcoinExchange::setDataBase( std::map<Time, float> &dataBase ){this->dataBase = dataBase;}
/***********************************/

/*         [Time Constructors]         */
Time::Time(unsigned int d, unsigned int m, unsigned y){
    if ((y>2023 || y<2008) || (m>12 || m<1))
        throw timeError();
    if ((m<=7 && m%2==0 && d>30) || (m>=8 && m%2 != 0 && d>30) || (m==2 && d > 28+(y%4==0)))
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
bool Time::operator>( const Time &a ){
    return (this->y>a.y) || (this->y==a.y && this->m>a.m) || (this->y==a.y && this->m==a.m && this->d>a.d);
}

bool Time::operator<( const Time &a ){
    return (this->y<a.y) || (this->y==a.y && this->m<a.m) || (this->y==a.y && this->m==a.m && this->d<a.d);
}

bool Time::operator>=( const Time &a ){
    return (this->y>=a.y) || (this->y==a.y && this->m>=a.m) || (this->y==a.y && this->m==a.m && this->d>=a.d);
}

bool Time::operator<=( const Time &a ){
    return (this->y<=a.y) || (this->y==a.y && this->m<=a.m) || (this->y==a.y && this->m==a.m && this->d<=a.d);
}

bool Time::operator==( const Time &a ){
    return this->y == a.y && this->m == a.m && this->d == a.d;
}

bool Time::operator!=( const Time &a ){
    return !(this->y == a.y && this->m == a.m && this->d == a.d);
}
/**************************************************/

/*         [Time Out Of Range Error]         */
const char *Time::timeError::what() const throw(){return "Error : Invalid Time";}
/*********************************************/
