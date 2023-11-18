/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 01:58:54 by faksouss          #+#    #+#             */
/*   Updated: 2023/11/18 02:38:30 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include<iostream>
#include<string>
#include<map>

typedef struct Time{
    unsigned int d;//Day
    unsigned int m;//Month
    unsigned int y;//Year
    /*         [Time Constructor]         */
    Time(unsigned int d, unsigned int m, unsigned y){
        if ((y > 2023 || y < 2008) || (m > 12 || m < 1))
            throw timeError();
        if ((m <= 7 && m % 2 == 0 && d > 30) || (m >= 8 && m%2 != 0 && d > 30) || (m == 2 && d > 28 + (y % 4 == 0)))
            throw timeError();
        this->d = d;
        this->m = m;
        this->y = y;
    }
    /*************************************/
    /*         [(=) Operator Overload]         */
    Time &operator=( const Time &date ){
        if (this != &date){this->d=date.d; this->m=date.m; this->y=date.y;}
        return *this;
    }
    /*******************************************/
    /*         [Comperation Operators Overload]         */
    bool operator>( const Time &a ){
        return (this->y>a.y) || (this->y==a.y && this->m>a.m) || (this->y==a.y && this->m==a.m && this->d>a.d);
    }

    bool operator<( const Time &a ){
        return (this->y<a.y) || (this->y==a.y && this->m<a.m) || (this->y==a.y && this->m==a.m && this->d<a.d);
    }

    bool operator>=( const Time &a ){
        return (this->y>=a.y) || (this->y==a.y && this->m>=a.m) || (this->y==a.y && this->m==a.m && this->d>=a.d);
    }
    
    bool operator<=( const Time &a ){
        return (this->y<=a.y) || (this->y==a.y && this->m<=a.m) || (this->y==a.y && this->m==a.m && this->d<=a.d);
    }

    bool operator==( const Time &a ){
        return this->y == a.y && this->m == a.m && this->d == a.d;
    }

    bool operator!=( const Time &a ){
        return !(this->y == a.y && this->m == a.m && this->d == a.d);
    }
    /**************************************************/
    /*         [Time Out Of Range Error]         */
    class timeError : public std::exception{
        public:
            virtual const char *what() const throw(){return "Invalid Time";}
    };
    /*********************************************/
} Time;
