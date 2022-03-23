#include <map>
#include <vector>
#include <string>
#include <fcntl.h>
#include <unistd.h>
#include <sys/system_properties.h>
#include "config.h"
#include "logging.h"

using namespace Config;

namespace Config {

    namespace Properties {

        void Put(const char *name, const char *value);
    }

    namespace Packages {

        void Add(const char *name);
    }
}


static std::map<std::string, Property *> props;
static std::vector<std::string> packages;

Property *Properties::Find(const char *name) {
    if (!name) return nullptr;

    auto it = props.find(name);
    if (it != props.end()) {
        return it->second;
    }
    return nullptr;
}

void Properties::Put(const char *name, const char *value) {
    if (!name) return;

    auto prop = Find(name);
    delete prop;

    props[name] = new Property(name, value ? value : "");

    LOGD("property: %s %s", name, value);
}

bool Packages::Find(const char *name) {
    if (!name) return false;
    return std::find(packages.begin(), packages.end(), name) != packages.end();
}

void Packages::Add(const char *name) {
    if (!name) return;
    packages.emplace_back(name);

    LOGD("package: %s", name);
}

void Config::Load() {
	Properties::Put("ro.product.manufacturer", "Xiaomi");
	Properties::Put("ro.product.brand", "Xiaomi");
	Properties::Put("ro.product.name", "Xiaomi");

	Packages::Add("com.tencent.weread");
	Packages::Add("cmb.pb");
	Packages::Add("cn.adidas.app");
	Packages::Add("cn.adidas.confirmed.app");
	Packages::Add("com.coolapk.market");
	Packages::Add("com.dianping.v1");
	Packages::Add("com.icbc");
	Packages::Add("com.sankuai.meituan");
	Packages::Add("com.smzdm.client.android");
	Packages::Add("com.starbucks.cn");
	Packages::Add("me.ele");
	Packages::Add("com.sf.activity");
	Packages::Add("cn.com.hkgt.gasapp");
	Packages::Add("com.heytap.health");
	Packages::Add("com.alicloud.databox");
	Packages::Add("info.muge.appshare");
	Packages::Add("com.chinamworld.main");
	Packages::Add("com.android.calendar");
	Packages::Add("com.miui.weather2");
	Packages::Add("com.android.email");
	Packages::Add("com.chaoxing.mobile");
	
	Packages::Add("com.ruanmei.ithome");
	Packages::Add("com.netease.cloudmusic");
	Packages::Add("com.baidu.BaiduMap");
	Packages::Add("com.autonavi.minimap");
	Packages::Add("com.jingdong.app.mall");
	Packages::Add("com.jd.jdlite");
	Packages::Add("com.tencent.wemeet.app");
	Packages::Add("com.tencent.mobileqq");
	Packages::Add("com.tencent.qqmusic");
	Packages::Add("com.tencent.qqlive");
	Packages::Add("com.tencent.androidqqmail");
	Packages::Add("com.tencent.tmgp.sgame");
	Packages::Add("com.alibaba.android.rimet");
	Packages::Add("com.taobao.taobao");
	Packages::Add("com.tmall.wireless");
	Packages::Add("com.cainiao.wireless");
	Packages::Add("com.taobao.idelfish");
	Packages::Add("com.taobao.trip");
	Packages::Add("com.taobao.movie.android");
	Packages::Add("com.eg.android.AlipayGphone");
	Packages::Add("com.wudaokou.hippo");
	Packages::Add("com.zhihu.android");
	Packages::Add("com.weico.international");
	Packages::Add("com.qiyi.video");
	Packages::Add("com.sdu.didi.psnger");
	Packages::Add("com.ss.android.ugc.aweme");
	Packages::Add("com.tmri.app.main");
	Packages::Add("cn.gov.tax.its");
	Packages::Add("com.sgcc.wsgw.cn");
	Packages::Add("com.MobileTicket");
	Packages::Add("com.xiachufang");
	Packages::Add("ctrip.android.view");
	Packages::Add("com.chinatelecom.bestpayclient");
	Packages::Add("com.ct.client");
	Packages::Add("com.cn21.ecloud");
	Packages::Add("com.yueme.itv");
	Packages::Add("com.youku.phone");
	Packages::Add("com.unionpay");
	Packages::Add("com.cmbchina.ccd.pluto.cmbActivity");
	Packages::Add("com.chinamworld.bocmbci");
	Packages::Add("com.bankcomm.maidanba");
	Packages::Add("com.csii.hkb");
	Packages::Add("com.whrcbank.mbank");
	Packages::Add("com.linroid.zlive");
	Packages::Add("com.t3go.passenger");
	Packages::Add("com.xiaomi.hm.health");
	Packages::Add("com.xiaomi.wearable");
	Packages::Add("com.umetrip.android.msky.app");
	Packages::Add("com.suning.mobile.ebuy");
	Packages::Add("com.duokan.phone.remotecontroller");
	Packages::Add("com.timanetworks.android.faw.vw.aftermarket.release");
	Packages::Add("com.lphtsccft");
	Packages::Add("com.cubic.autohome");
	Packages::Add("com.baidu.netdisk.samsung");
	Packages::Add("com.baidu.tieba");
	Packages::Add("com.chinamobile.mcloud");
	Packages::Add("com.dragon.read");
	Packages::Add("com.dmzj.manhua");
	Packages::Add("com.dmzjsq.manhua");
	Packages::Add("com.douban.frodo");
	Packages::Add("com.faloo.BookReader4Android");
	Packages::Add("com.greenpoint.android.mc10086.activity");
	Packages::Add("com.kuangxiangciweimao.novel");
	Packages::Add("com.nowcasting.activity");
	Packages::Add("com.novel.du");
	Packages::Add("com.qidian.QDReader");
	Packages::Add("com.readunion.ireader");
	Packages::Add("com.sfacg");
	Packages::Add("com.sitech.ac");
	Packages::Add("com.tencent.mp");
	Packages::Add("com.xunlei.downloadprovider");
	Packages::Add("com.xingin.xhs");
	Packages::Add("com.xunyou.rb");
	Packages::Add("com.yingyonghui.market");
	Packages::Add("com.youdu");
	Packages::Add("com.youdao.translator");
	Packages::Add("cn.wps.moffice_eng");
	Packages::Add("hanjie.app.pureweather");
	Packages::Add("nutstore.android");
	Packages::Add("com.nowcasting.activity");
	Packages::Add("com.hpbr.bosszhipin");
	Packages::Add("com.zhaopin.social");
	Packages::Add("com.taobao.etao");
	Packages::Add("com.cib.cibmb");
	Packages::Add("com.sina.weibo");
	Packages::Add("com.job.android");
	Packages::Add("net.evecom.android.mztapp");
	Packages::Add("today.tophub.app");
	Packages::Add("com.cebbank.mobile.cemb");
	Packages::Add("com.duoduo.tuanzhang");
	Packages::Add("tv.danmaku.bili");
	Packages::Add("top.tdtt.news");
	Packages::Add("com.xunmeng.pinduoduo");
	Packages::Add("com.digitalchina.mobile.dfhfz1");
	Packages::Add("com.ss.android.article.news");
}

