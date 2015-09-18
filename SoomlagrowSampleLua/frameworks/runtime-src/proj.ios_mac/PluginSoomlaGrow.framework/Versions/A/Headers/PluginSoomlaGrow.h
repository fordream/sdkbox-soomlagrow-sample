/****************************************************************************
 
 Copyright (c) 2014-2015 Chukong Technologies
 
 ****************************************************************************/

#ifndef __PLUGIN_SOOMLA_GROW_H__
#define __PLUGIN_SOOMLA_GROW_H__

#include <string>
#include <map>

namespace sdkbox {
    
    class SoomlaGrowListener {
    public:
        /**
         * This event is triggered once the highway initialized.
         */
        virtual void onGrowInitialized() = 0;
        
        /**
         * This event is triggered once the highway is connected to server.
         */
        virtual void onGrowConnected() = 0;
        
        /**
         * This event is triggered once the highway disconnect from the server.
         */
        virtual void onGrowDisconnected() = 0;
        
        /**
         * This event is triggered once the grow insight initialized.
         */
        virtual void onGrowInsightsInitialized() = 0;
        
        /**
         * This event is triggered once the grow insight refresh failed.
         */
        virtual void onInsightsRefreshFailed() = 0;
        
        /**
         * This event is triggered once the grow insight refresh finished.
         */
        virtual void onInsightsRefreshFinished() = 0;
        
        /**
         * This event is triggered once the grow insight refresh started.
         */
        virtual void onInsightsRefreshStarted() = 0;
    };
    
    class PluginSoomlaGrow {
    public:
        typedef enum {
            Action=0,
            Adventure=1,
            Arcade=2,
            Board=3,
            Card=4,
            Casino=5,
            Casual=6,
            Educational=7,
            Family=8,
            Music=9,
            Puzzle=10,
            Racing=11,
            Role_Playing=12,
            Simulation=13,
            Sports=14,
            Strategy=15,
            Trivia=16,
            Word=17
        } EGenre;
        
        typedef enum {
            _12am_6am=0,
            _6am_12pm=1,
            _12pm_6pm=2,
            _6pm_12am=3
        } EDayQuarter;
        
        /**
         * initialize the plugin instance.
         */
        static bool init();
        
        /**
         * Set listener to listen for different events (list below)
         */
        static void setListener(SoomlaGrowListener* lis);
        
        /**
         * get Listener of soomla grow
         */
        static SoomlaGrowListener* getListener();
        
        /**
         * remove Listener in soomla grow
         */
        static void removeListener();
        
        /**
         * Refreshed GROW's Insights information from the server
         */
        static void refreshInsights();

        /**
         * get pay rank
         */
        static int payRank(EGenre genre);
        
        /**
         * purchase likelihood time
         */
        static double purchaseLikelihood(EDayQuarter dayquarter);
        
    };
}

#endif
