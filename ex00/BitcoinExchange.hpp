/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 01:58:54 by faksouss          #+#    #+#             */
/*   Updated: 2023/11/19 03:46:40 by faksouss         ###   ########.fr       */
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
    
    /*         [Time Constructors]         */
    Time(unsigned int d, unsigned int m, unsigned y);
    Time( void );
    /*************************************/

    /*         [(=) Operator Overload]         */
    Time &operator=( const Time &date );
    /*******************************************/
    
    /*         [Comperation Operators Overload]         */
    bool operator>( const Time &a );
    bool operator<( const Time &a );
    bool operator>=( const Time &a );
    bool operator<=( const Time &a );
    bool operator==( const Time &a );
    bool operator!=( const Time &a );
    /**************************************************/
    
    /*         [Time Out Of Range Error]         */
    class timeError : public std::exception{
        public:
            virtual const char *what() const throw();
    };
    /*********************************************/
} Time;

class BitcoinExchange{
    private:
        std::map<Time, float> dataBase;
    public:
        /*[BitcoinExchange Constructors & Deconstrucot]*/
        BitcoinExchange( void );
        BitcoinExchange( const BitcoinExchange &obj );
        ~BitcoinExchange( void );
        /************************************************/
        /*         [(=) Operator Overload]         */
        BitcoinExchange &operator=( const BitcoinExchange &obj );
        /*******************************************/
        /*        [Geters & Seters]        */
        void setDataBase( std::map<Time, float> &dataBase );
        std::map<Time, float> getDataBase( void ) const;
        /***********************************/
};
