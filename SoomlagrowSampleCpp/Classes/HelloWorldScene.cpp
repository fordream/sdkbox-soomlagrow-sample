#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    _productName = "";
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...
    
    Menu* list = Menu::create(
                              MenuItemFont::create("FB Login", CC_CALLBACK_1(HelloWorld::onLoginClicked, this)),
                              MenuItemFont::create("FB Share", CC_CALLBACK_1(HelloWorld::onShareClicked, this)),
                              MenuItemFont::create("IAP Restore", CC_CALLBACK_1(HelloWorld::onRestoreClicked, this)),
                              MenuItemFont::create("IAP Refresh", CC_CALLBACK_1(HelloWorld::onRefreshClicked, this)),
                              MenuItemFont::create("IAP Purchase", CC_CALLBACK_1(HelloWorld::onPurchaseClicked, this)),
                              NULL);
    list->alignItemsVerticallyWithPadding(5);
    list->setPosition(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2);
    addChild(list);
    
    auto label = Label::createWithTTF("events of IAP and Facebook will send to soomla", "fonts/arial.ttf", 8);
    label->setPosition(origin.x + visibleSize.width/2, 30);
    addChild(label);
    
    sdkbox::IAP::setListener(this);
    sdkbox::IAP::init();
    
    sdkbox::PluginFacebook::setListener(this);
    sdkbox::PluginFacebook::init();

    sdkbox::PluginSoomlaGrow::setListener(this);
    sdkbox::PluginSoomlaGrow::init();
    
    sdkbox::PluginSoomlaGrow::refreshInsights();
    
    sdkbox::IAP::refresh();
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::onLoginClicked(cocos2d::Ref* sender) {
    if (!sdkbox::PluginFacebook::isLoggedIn()) {
        sdkbox::PluginFacebook::login();
    }
}

void HelloWorld::onShareClicked(cocos2d::Ref* sender) {
    sdkbox::FBShareInfo info;
    info.type  = sdkbox::FB_LINK;
    info.link  = "http://www.cocos2d-x.org";
    info.title = "cocos2d-x";
    info.text  = "Best Game Engine";
    info.image = "http://cocos2d-x.org/images/logo.png";
    
    bool canPresent = sdkbox::PluginFacebook::canPresentWithFBApp(info);
    CCLOG("##FB can present with facebook app: %s", canPresent ? "yes" : "no");
    if (!canPresent)
    {
        CCLOG("\n\n##FB ****************************");
        CCLOG("##FB will show web dialog for u, openning web browser...");
        CCLOG("##FB ****************************\n\n");
    }
    
    sdkbox::PluginFacebook::dialog(info);
}

void HelloWorld::onRestoreClicked(cocos2d::Ref* sender) {
    sdkbox::IAP::restore();
}

void HelloWorld::onRefreshClicked(cocos2d::Ref* sender) {
    sdkbox::IAP::refresh();
}

void HelloWorld::onPurchaseClicked(cocos2d::Ref *sender) {
    if (_productName.length() > 0) {
        sdkbox::IAP::purchase(_productName);
    }
}


//IAP Listener
void HelloWorld::onInitialized(bool ok)
{
    CCLOG("%s : %d", __func__, ok);
}

void HelloWorld::onSuccess(const sdkbox::Product &p)
{
    CCLOG("Purchase Success: %s", p.id.c_str());
}

void HelloWorld::onFailure(const sdkbox::Product &p, const std::string &msg)
{
    CCLOG("Purchase Failed: %s", msg.c_str());
}

void HelloWorld::onCanceled(const sdkbox::Product &p)
{
    CCLOG("Purchase Canceled: %s", p.id.c_str());
}

void HelloWorld::onRestored(const sdkbox::Product& p)
{
    CCLOG("Purchase Restored: %s", p.name.c_str());
}

void HelloWorld::onProductRequestSuccess(const std::vector<sdkbox::Product> &products)
{
    CCLOG("onProductRequestSuccess:");
    if (products.size() > 0) {
        _productName = products[0].name;
    } else {
        _productName = "";
    }
}

void HelloWorld::onProductRequestFailure(const std::string &msg)
{
    CCLOG("IAP onProductRequestFailure");
    _productName = "";
}

void HelloWorld::onRestoreComplete(bool ok, const std::string &msg)
{
    CCLOG("onRestoreComplete %d:%s", ok, msg.data());
}

//Facebook Listener
// Event callbacks
void HelloWorld::onLogin(bool isLogin, const std::string& error)
{
    CCLOG("##FB isLogin: %d, error: %s", isLogin, error.c_str());
    
    std::string title = "login ";
    title.append((isLogin ? "success" : "failed"));
    MessageBox(error.c_str(), title.c_str());
}
void HelloWorld::onAPI(const std::string& tag, const std::string& jsonData)
{
    CCLOG("##FB onAPI: tag -> %s, json -> %s", tag.c_str(), jsonData.c_str());
}
void HelloWorld::onSharedSuccess(const std::string& message)
{
    CCLOG("##FB onSharedSuccess:%s", message.c_str());
    
    MessageBox(message.c_str(), "share success");
}
void HelloWorld::onSharedFailed(const std::string& message)
{
    CCLOG("##FB onSharedFailed:%s", message.c_str());
    
    MessageBox(message.c_str(), "share failed");
}
void HelloWorld::onSharedCancel()
{
    CCLOG("##FB onSharedCancel");
    
    MessageBox("", "share cancel");
}
void HelloWorld::onPermission(bool isLogin, const std::string& error)
{
    CCLOG("##FB onPermission: %d, error: %s", isLogin, error.c_str());
    
    std::string title = "permission ";
    title.append((isLogin ? "success" : "failed"));
    MessageBox(error.c_str(), title.c_str());
}
void HelloWorld::onFetchFriends(bool ok, const std::string& msg)
{
    CCLOG("##FB %s: %d = %s", __FUNCTION__, ok, msg.data());
    
    const std::vector<sdkbox::FBGraphUser>& friends = sdkbox::PluginFacebook::getFriends();
    for (int i = 0; i < friends.size(); i++)
    {
        const sdkbox::FBGraphUser& user = friends.at(i);
        CCLOG("##FB> -------------------------------");
        CCLOG("##FB>> %s", user.uid.data());
        CCLOG("##FB>> %s", user.firstName.data());
        CCLOG("##FB>> %s", user.lastName.data());
        CCLOG("##FB>> %s", user.name.data());
        CCLOG("##FB>> %s", user.isInstalled ? "app is installed" : "app is not installed");
        CCLOG("##FB");
    }
    
    MessageBox("", "fetch friends");
}

//Soomla Grow Listener
void HelloWorld::onGrowInitialized() {
    CCLOG("Soomla Grow event initialized");
}

void HelloWorld::onGrowConnected() {
    CCLOG("Soomla Grow event connected");
}

void HelloWorld::onGrowDisconnected() {
    CCLOG("Soomla Grow event disconnected");
}

void HelloWorld::onGrowInsightsInitialized() {
    CCLOG("Soomla Grow insight initialized");
}

void HelloWorld::onInsightsRefreshFailed() {
    CCLOG("Soomla Grow insight refresh failed");
}

void HelloWorld::onInsightsRefreshFinished() {
    CCLOG("Soomla Grow insight refresh finished");
}

void HelloWorld::onInsightsRefreshStarted() {
    CCLOG("Soomla Grow insight refresh started");
}

