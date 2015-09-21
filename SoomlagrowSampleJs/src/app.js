
var HelloWorldLayer = cc.Layer.extend({
    sprite:null,
    ctor:function () {
        //////////////////////////////
        // 1. super init first
        this._super();

        /////////////////////////////
        // 2. add a menu item with "X" image, which is clicked to quit the program
        //    you may modify it.
        // ask the window size
        var size = cc.winSize;

        /////////////////////////////
        // 3. add your codes below...
        // add a label shows "Hello World"
        // create and initialize a label
        var helloLabel = new cc.LabelTTF("events of IAP and Facebook will send to soomla", "Arial", 15);
        // position the label on the center of the screen
        helloLabel.x = size.width / 2;
        helloLabel.y = 20;
        // add the label as a child to this layer
        this.addChild(helloLabel, 5);

        // add "HelloWorld" splash screen"
        // this.sprite = new cc.Sprite(res.HelloWorld_png);
        // this.sprite.attr({
        //     x: size.width / 2,
        //     y: size.height / 2
        // });
        // this.addChild(this.sprite, 0);

        var item1 = new cc.MenuItemFont("FB login", this.onLoginClicked, this);
        var item2 = new cc.MenuItemFont("FB Share", this.onShareClicked, this);
        var item3 = new cc.MenuItemFont("IAP Restore", this.onRestoreClicked, this);
        var item4 = new cc.MenuItemFont("IAP Refresh", this.onRefreshClicked, this);
        var item5 = new cc.MenuItemFont("IAP Purchase", this.onPurchaseClicked, this);

        var menu = new cc.Menu(item1, item2, item3, item4, item5);
        menu.x = size.width/2
        menu.y = size.height/2;
        menu.alignItemsVerticallyWithPadding(20);
        this.addChild(menu)

        return true;
    },
    initSDK: function() {
        sdkbox.IAP.setListener({
            onSuccess : function (product) {
                //Purchase success
            },
            onFailure : function (product, msg) {
                //Purchase failed
                //msg is the error message
            },
            onCanceled : function (product) {
                //Purchase was canceled by user
            },
            onRestored : function (product) {
                //Purchase restored
            },
            onProductRequestSuccess : function (products) {
                //Returns you the data for all the iap products
                //You can get each item using following method
                if (products.length > 0) {
                    this._productName = products[0].name;
                }
                for (var i = 0; i < products.length; i++) {
                }
            },
            onProductRequestFailure : function (msg) {
                //When product refresh request fails.
            },
            onRestoreComplete: function() {
                //when restore complete
            }
        });
        sdkbox.IAP.init();

        sdkbox.PluginFacebook.setListener({
            onLogin: function(isLogin, msg) {},
            onAPI: function(tag, data) {},
            onSharedSuccess: function(data) {},
            onSharedFailed: function(data) {},
            onSharedCancel: function() {},
            onPermission: function(isLogin, msg) {}
        });
        sdkbox.PluginFacebook.init();

        sdkbox.PluginSoomlaGrow.setListener({
            onLogin: function(isLogin, msg) {},
            onAPI: function(tag, data) {},
            onSharedSuccess: function(data) {},
            onSharedFailed: function(data) {},
            onSharedCancel: function() {},
            onPermission: function(isLogin, msg) {}
        });
        sdkbox.PluginSoomlaGrow.init();
    },

    onLoginClicked: function() {
        sdkbox.PluginFacebook.login();
    },
    onShareClicked: function() {
        var info = {};
        info.type  = sdkbox.FB_LINK;
        info.link  = "http://www.cocos2d-x.org";
        info.title = "cocos2d-x";
        info.text  = "Best Game Engine";
        info.image = "http://cocos2d-x.org/images/logo.png";

        sdkbox.PluginFacebook.dialog(info)
    },
    onRestoreClicked: function() {
        sdkbox.IAP.restore()
    },
    onRefreshClicked: function() {
        sdkbox.IAP.refresh()
    },
    onPurchaseClicked: function() {
        if (this._productName) {
            sdkbox.IAP.purchase(this._productName)
        }
    }
});

var HelloWorldScene = cc.Scene.extend({
    onEnter:function () {
        this._super();
        var layer = new HelloWorldLayer();
        this.addChild(layer);
    }
});

