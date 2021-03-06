/******************************************************************************
 *
 * $Id$
 *
 * Project:  WindNinja
 * Purpose:  Handle threading exceptions
 * Author:   Kyle Shannon <kyle@pobox.com>
 *
 ******************************************************************************
 *
 * THIS SOFTWARE WAS DEVELOPED AT THE ROCKY MOUNTAIN RESEARCH STATION (RMRS)
 * MISSOULA FIRE SCIENCES LABORATORY BY EMPLOYEES OF THE FEDERAL GOVERNMENT 
 * IN THE COURSE OF THEIR OFFICIAL DUTIES. PURSUANT TO TITLE 17 SECTION 105 
 * OF THE UNITED STATES CODE, THIS SOFTWARE IS NOT SUBJECT TO COPYRIGHT 
 * PROTECTION AND IS IN THE PUBLIC DOMAIN. RMRS MISSOULA FIRE SCIENCES 
 * LABORATORY ASSUMES NO RESPONSIBILITY WHATSOEVER FOR ITS USE BY OTHER 
 * PARTIES,  AND MAKES NO GUARANTEES, EXPRESSED OR IMPLIED, ABOUT ITS QUALITY, 
 * RELIABILITY, OR ANY OTHER CHARACTERISTIC.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 *****************************************************************************/

#include "ninja_threaded_exception.h"

void NinjaRethrowThreadedException( std::vector<int> anErrors,
                                    std::vector<std::string> asMessages,
                                    int nThreads )
{
    if( nThreads != anErrors.size() )
        nThreads = anErrors.size();
    for( int i=0; i < nThreads; i++ )
    {
        if( !anErrors[i] )
            continue;
        switch( anErrors[i] )
        {
            case STD_RUNTIME_EXC:
                 throw std::runtime_error( asMessages[i] );
             case STD_BAD_ALLOC_EXC:
                 throw std::bad_alloc();
             case STD_LOGIC_EXC:
                 throw std::logic_error( asMessages[i] );
             case STD_EXC:
             case STD_UNKNOWN_EXC:
                 throw std::exception();
             case NINJA_CANCEL_USER_EXC:
                 throw cancelledByUser();
             case NINJA_BAD_FORECAST_EXC:
                 throw badForecastFile( asMessages[i] );
             default:
                 break;
        }
    }
}

