#include <iostream>
#include "Investment.h"
#include "InvestmentKeeper.h"

Investment *g_pInvestment = NULL;

Investment * createInvestment()
// factory function
{
    if( g_pInvestment == NULL ) {
        g_pInvestment = new Investment( 10 );
    }
    return g_pInvestment;
}

void ReleaseInvestmentDirectly( Investment *pInv )
{
    delete pInv;
    pInv = NULL;
}

const int& GetDaysHeld( Investment *pInv )
{
    return pInv->GetDaysHeld();
}

int SomeCheckFunction( void )
{
    std::cout << "SomeCheckFunction" << std::endl;

    g_pInvestment = NULL;

    // throw "qwuqwuqwu do soming evil here";
    // 

    return 0;
}

void ProcessInvestment( const int& nSomeCheckFunctionRetValue, const InvestmentKeeper& Keeper )
{
    std::cout << "ProcessInvestment" << std::endl;

    if( nSomeCheckFunctionRetValue ) {
        // do something
    }
    else {
        // do something
    }
}

void ProcessInvestment( const InvestmentKeeper& Keeper, const int& nSomeCheckFunctionRetValue )
{
    std::cout << "ProcessInvestment" << std::endl;

    if( nSomeCheckFunctionRetValue ) {
        // do something
    }
    else {
        // do something
    }
}

void ProcessInvestment( std::shared_ptr< Investment > pSharedInv, const int& nSomeCheckFunctionRetValue )
{
    std::cout << "ProcessInvestment" << std::endl;

    if( nSomeCheckFunctionRetValue ) {
        // do something
    }
    else {
        // do something
    }
}

void ExampleI( void )
{
    // Shard_ptr example
    // ProcessInvestment( std::shared_ptr< Investment >( createInvestment() ), SomeCheckFunction() );

    // std::shared_ptr< Investment >SharedInv( createInvestment() );
    // ProcessInvestment( SharedInv, SomeCheckFunction() );

    ProcessInvestment( SomeCheckFunction(), InvestmentKeeper( createInvestment() ) );
    // ProcessInvestment( InvestmentKeeper( createInvestment() ), SomeCheckFunction() );
}

int main( void ) {
    
    ExampleI();

    return 0;
}

