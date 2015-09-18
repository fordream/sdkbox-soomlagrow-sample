
local MainScene = class("MainScene", cc.load("mvc").ViewBase)

function MainScene:onCreate()

    -- add HelloWorld label
    cc.Label:createWithSystemFont("events of IAP and Facebook will send to soomla", "Arial", 12)
        :move(display.cx, 20)
        :addTo(self)

    cc.Menu:create(
        cc.MenuItemFont:create("FB Login"):onClicked(function() self:onLoginClicked() end),
        cc.MenuItemFont:create("FB Share"):onClicked(function() self:onShareClicked() end),
        cc.MenuItemFont:create("IAP Restore"):onClicked(function() self:onRestoreClicked() end),
        cc.MenuItemFont:create("IAP Refresh"):onClicked(function() self:onRefreshClicked() end),
        cc.MenuItemFont:create("IAP Purchase"):onClicked(function() self:onPurchaseClicked() end))
            :move(display.cx, display.cy)
            :alignItemsVerticallyWithPadding(5)
            :addTo(self)

    self:initSDK()
end

function MainScene:initSDK()
    sdkbox.IAP:setListener(function(args)
        if "onSuccess" == args.event then
                local product = args.product
                dump(product, "onSuccess:")
        elseif "onFailure" == args.event then
                local product = args.product
                local msg = args.msg
                dump(product, "onFailure:")
                print("msg:", msg)
        elseif "onCanceled" == args.event then
                local product = args.product
                dump(product, "onCanceled:")
        elseif "onRestored" == args.event then
                local product = args.product
                dump(product, "onRestored:")
        elseif "onProductRequestSuccess" == args.event then
                local products = args.products
                dump(products, "onProductRequestSuccess:")
                if #products > 0 then
                    self._productName = products[1].name
                else
                    self._productName = nil
                end
        elseif "onProductRequestFailure" == args.event then
                local msg = args.msg
                print("msg:", msg)
        elseif "onRestoreComplete" == args.event then
            print "onRestoreComplete"
        else
                print("unknow event ", args.event)
        end
    end)
    sdkbox.IAP:init()

    sdkbox.PluginFacebook:setListener(function(args)
        if "onLogin" == args.name then
            local isLogin = args.isLogin;
            local msg = args.msg;
        elseif "onPermission" ==  args.name then
            local isLogin = args.isLogin;
            local msg = args.msg;
        elseif "onAPI" ==  args.name then
            local tag = args.tag;
            local jsonData = args.jsonData;
        elseif "onSharedSuccess" ==  args.name then
            local msg = args.message
        elseif "onSharedFailed" ==  args.name then
            local msg = args.message
        elseif "onSharedCancel" ==  args.name then
        end
    end)
    sdkbox.PluginFacebook:init()

    sdkbox.PluginSoomlaGrow:setListener(function(data)
        dump(data, "Soomla Grow Event:")
        if "onGrowInitialized" == data.event then
        elseif "onGrowConnected" == data.event then
        elseif "onGrowDisconnected" == data.event then
        elseif "onGrowInsightsInitialized" == data.event then
        elseif "onInsightsRefreshFailed" == data.event then
        elseif "onInsightsRefreshFinished" == data.event then
        elseif "onInsightsRefreshStarted" == data.event then
        end
    end)
    sdkbox.PluginSoomlaGrow:init()
end

function MainScene:onLoginClicked()
    if not sdkbox.PluginFacebook:isLoggedIn() then
        sdkbox.PluginFacebook:login()
    end
end

function MainScene:onShareClicked()
    local info = {};
    info.type  = sdkbox.FB_LINK;
    info.link  = "http://www.cocos2d-x.org";
    info.title = "cocos2d-x";
    info.text  = "Best Game Engine";
    info.image = "http://cocos2d-x.org/images/logo.png";

    local canPresent = sdkbox.PluginFacebook:canPresentWithFBApp(info)
    if canPresent then
        print("\n\n##FB ****************************");
        print("##FB will show web dialog for u, openning web browser...");
        print("##FB ****************************\n\n");
    end

    sdkbox.PluginFacebook:dialog(info)
end

function MainScene:onRestoreClicked()
    sdkbox.IAP:restore()
end

function MainScene:onRefreshClicked()
    sdkbox.IAP:refresh()
end

function MainScene:onPurchaseClicked()
    if self._productName then
        sdkbox.IAP:purchase(self._productName)
    end
end

return MainScene
