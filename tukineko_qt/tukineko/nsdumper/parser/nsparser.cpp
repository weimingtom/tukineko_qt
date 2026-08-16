#include <QDebug>
#include <QTextCodec>
#include <QCoreApplication>

#include "nsparser.h"
#include "nscripter.h"
#include "util.h"

#include "fcommand.h"
#include "gamecommand.h"
#include "intlimitcommand.h"
#include "savenumbercommand.h"
#include "addcommand.h"

#include "atoicommand.h"
#include "cmpcommand.h"
#include "datecommand.h"
#include "deccommand.h"
#include "divcommand.h"
#include "endcommand.h"
#include "getinicommand.h"
#include "getregcommand.h"
#include "gosubcommand.h"
#include "ifcommand.h"
#include "inccommand.h"
#include "itoacommand.h"
#include "jumpbcommand.h"
#include "jumpfcommand.h"
#include "loadgamecommand.h"
#include "modcommand.h"
#include "movcommand.h"
#include "mulcommand.h"
#include "notifcommand.h"
#include "returncommand.h"
#include "rndcommand.h"
#include "rnd2command.h"
#include "savegamecommand.h"
#include "skipcommand.h"
#include "subcommand.h"
#include "timecommand.h"

#include "ecommand.h"
#include "btncommand.h"
#include "btndefcommand.h"
#include "btnwaitcommand.h"
#include "btnwait2command.h"
#include "clickcommand.h"
#include "clickposcommand.h"
#include "defineresetcommand.h"
#include "delaycommand.h"
#include "gettimercommand.h"
#include "inputstrcommand.h"
#include "lookbackflushcommand.h"
#include "resetcommand.h"
#include "resettimercommand.h"
#include "rmodecommand.h"
#include "selectcommand.h"
#include "selgosubcommand.h"
#include "selnumcommand.h"
#include "systemcallcommand.h"
#include "textspeedcommand.h"
#include "trapcommand.h"
#include "waitcommand.h"
#include "waittimercommand.h"

#include "saveoncommand.h"
#include "saveoffcommand.h"
#include "gotocommand.h"

#include "secommand.h"
#include "abssetcursorcommand.h"
#include "setcursorcommand.h"
#include "setwindowcommand.h"

#include "arccommand.h"
#include "bgaliacommand.h"
#include "cdfadeoutcommand.h"
#include "clickstrcommand.h"
#include "clickvoicecommand.h"
#include "defaultfontcommand.h"
#include "defspeedcommand.h"
#include "dsoundcommand.h"
#include "effectblankcommand.h"
#include "effectcommand.h"
#include "filelogcommand.h"
#include "globaloncommand.h"
#include "humanzcommand.h"
#include "killmenucommand.h"
#include "labellogcommand.h"
#include "lookbackbuttoncommand.h"
#include "lookbackcolorcommand.h"
#include "lookbackvoicecommand.h"
#include "menuselectcolorcommand.h"
#include "menuselectvoicecommand.h"
#include "menusetwindowcommand.h"
#include "nsacommand.h"
#include "numaliascommand.h"
#include "rlookbackcommand.h"
#include "rmenucommand.h"
#include "roffcommand.h"
#include "savenamecommand.h"
#include "selectcolorcommand.h"
#include "selectvoicecommand.h"
#include "sfcommand.h"
#include "soundpressplgincommand.h"
#include "spicommand.h"
#include "straliascommand.h"
#include "transmodecommand.h"
#include "underlinecommand.h"
#include "versionstrcommand.h"

#include "mesboxcommand.h"
#include "vfecommand.h"

#include "captioncommand.h"
#include "getversioncommand.h"
#include "mousecursorcommand.h"
#include "sfecommand.h"
#include "windoweffectcommand.h"

#include "autoclickcommand.h"
#include "avicommand.h"
#include "bgcommand.h"
#include "bltcommand.h"
#include "brcommand.h"
#include "clcommand.h"
#include "cspcommand.h"
#include "dwavecommand.h"
#include "dwaveloopcommand.h"
#include "dwavestopcommand.h"
#include "erasetextwindowcommand.h"
#include "ldcommand.h"
#include "locatecommand.h"
#include "lspcommand.h"
#include "lsphcommand.h"
#include "menuclickdefcommand.h"
#include "menuclickpagecommand.h"
#include "menufullcommand.h"
#include "menuwindowcommand.h"
#include "monocrocommand.h"
#include "mp3command.h"
#include "mp3loopcommand.h"
#include "mspcommand.h"
#include "negacommand.h"
#include "ofscpycommand.h"
#include "playcommand.h"
#include "playoncecommand.h"
#include "playstopcommand.h"
#include "printcommand.h"
#include "puttextcommand.h"
#include "quakexcommand.h"
#include "quakeycommand.h"
#include "stopcommand.h"
#include "talcommand.h"
#include "textclearcommand.h"
#include "textoffcommand.h"
#include "textoncommand.h"
#include "vecommand.h"
#include "vspcommand.h"
#include "wavecommand.h"
#include "waveloopcommand.h"
#include "wavestopcommand.h"

NsParser::NsParser(const QString& path_)
    : path(path_)
{
    initParser();
}

NsParser::~NsParser()
{
    qDeleteAll(sfCommands);
    qDeleteAll(sfeCommands);
    qDeleteAll(seCommands);
    qDeleteAll(vfeCommands);
    qDeleteAll(veCommands);
    qDeleteAll(fCommands);
    qDeleteAll(eCommands);
    qDeleteAll(feCommands);
}

void NsParser::initParser()
{
    // SF Commands (Define-time, file-level)
    sfCommands.append(new LookbackbuttonCommand());
    sfCommands.append(new LookbackcolorCommand());
    sfCommands.append(new SavenameCommand());
    sfCommands.append(new ClickstrCommand());
    sfCommands.append(new FilelogCommand());
    sfCommands.append(new LabellogCommand());
    sfCommands.append(new SoundpressplginCommand());
    sfCommands.append(new VersionstrCommand());
    sfCommands.append(new EffectblankCommand());
    sfCommands.append(new BgaliaCommand());
    sfCommands.append(new CdfadeoutCommand());
    sfCommands.append(new SpiCommand());
    sfCommands.append(new ArcCommand());
    sfCommands.append(new NsaCommand());
    sfCommands.append(new EffectCommand());
    sfCommands.append(new TransmodeCommand());
    sfCommands.append(new StraliasCommand());
    sfCommands.append(new NumaliasCommand());
    sfCommands.append(new DefaultfontCommand());
    sfCommands.append(new SelectcolorCommand());
    sfCommands.append(new MenuselectcolorCommand());
    sfCommands.append(new LookbackvoiceCommand());
    sfCommands.append(new ClickvoiceCommand());
    sfCommands.append(new SelectvoiceCommand());
    sfCommands.append(new MenuselectvoiceCommand());
    sfCommands.append(new GlobalonCommand());
    sfCommands.append(new HumanzCommand());
    sfCommands.append(new UnderlineCommand());
    sfCommands.append(new RlookbackCommand());
    sfCommands.append(new RoffCommand());
    sfCommands.append(new RmenuCommand());
    sfCommands.append(new MenusetwindowCommand());
    sfCommands.append(new KillmenuCommand());
    sfCommands.append(new DefSpeedCommand());
    sfCommands.append(new DsoundCommand());

    // SFE Commands (Define-time, effect-level)
    sfeCommands.append(new WindoweffectCommand());
    sfeCommands.append(new MousecursorCommand());
    sfeCommands.append(new CaptionCommand());
    sfeCommands.append(new GetversionCommand());

    // SE Commands (Define-time, global)
    seCommands.append(new AbssetcursorCommand());
    seCommands.append(new SetcursorCommand());
    seCommands.append(new SetwindowCommand());

    // VFE Commands (Visual, file-level effect)
    vfeCommands.append(new MesboxCommand());

    // VE Commands (Visual, global)
    veCommands.append(new LocateCommand());
    veCommands.append(new PuttextCommand());
    veCommands.append(new AutoclickCommand());
    veCommands.append(new BrCommand());
    veCommands.append(new QuakexCommand());
    veCommands.append(new QuakeyCommand());
    veCommands.append(new ErasetextwindowCommand());
    veCommands.append(new TextoffCommand());
    veCommands.append(new TextonCommand());
    veCommands.append(new TextclearCommand());
    veCommands.append(new MenufullCommand());
    veCommands.append(new MenuwindowCommand());
    veCommands.append(new MenuclickpageCommand());
    veCommands.append(new MenuclickdefCommand());
    veCommands.append(new MonocroCommand());
    veCommands.append(new NegaCommand());
    veCommands.append(new BgCommand());
    veCommands.append(new LdCommand());
    veCommands.append(new ClCommand());
    veCommands.append(new PrintCommand());
    veCommands.append(new TalCommand());
    veCommands.append(new LspCommand());
    veCommands.append(new LsphCommand());
    veCommands.append(new CspCommand());
    veCommands.append(new VspCommand());
    veCommands.append(new MspCommand());
    veCommands.append(new PlayCommand());
    veCommands.append(new PlayonceCommand());
    veCommands.append(new StopCommand());
    veCommands.append(new WaveCommand());
    veCommands.append(new WaveloopCommand());
    veCommands.append(new WavestopCommand());
    veCommands.append(new PlaystopCommand());
    veCommands.append(new Mp3Command());
    veCommands.append(new Mp3loopCommand());
    veCommands.append(new AviCommand());
    veCommands.append(new DwaveCommand());
    veCommands.append(new DwaveloopCommand());
    veCommands.append(new DwavestopCommand());
    veCommands.append(new BltCommand());
    veCommands.append(new OfscpyCommand());

    // F Commands (Execute-time, file-level)
    fCommands.append(new IntlimitCommand());
    fCommands.append(new SavenumberCommand());
    fCommands.append(new GameCommand());

    // E Commands (Execute-time, global)
    eCommands.append(new RmodeCommand());
    eCommands.append(new SystemcallCommand());
    eCommands.append(new TrapCommand());
    eCommands.append(new SelectCommand());
    eCommands.append(new SelgosubCommand());
    eCommands.append(new SelnumCommand());
    eCommands.append(new ResettimerCommand());
    eCommands.append(new GettimerCommand());
    eCommands.append(new ClickCommand());
    eCommands.append(new ResetCommand());
    eCommands.append(new DefineresetCommand());
    eCommands.append(new DelayCommand());
    eCommands.append(new WaitCommand());
    eCommands.append(new TextspeedCommand());
    eCommands.append(new LookbackflushCommand());
    eCommands.append(new InputstrCommand());
    eCommands.append(new ClickposCommand());
    eCommands.append(new BtndefCommand());
    eCommands.append(new BtnCommand());
    eCommands.append(new BtnwaitCommand());
    eCommands.append(new Btnwait2Command());

    // FE Commands (Execute-time, file-level)
    feCommands.append(new EndCommand());
    feCommands.append(new MovCommand());
    feCommands.append(new RndCommand());
    feCommands.append(new Rnd2Command());
    feCommands.append(new GetregCommand());
    feCommands.append(new GetiniCommand());
    feCommands.append(new AddCommand());
    feCommands.append(new SubCommand());
    feCommands.append(new IncCommand());
    feCommands.append(new DecCommand());
    feCommands.append(new MulCommand());
    feCommands.append(new DivCommand());
    feCommands.append(new ModCommand());
    feCommands.append(new GotoCommand());
    feCommands.append(new SkipCommand());
    feCommands.append(new GosubCommand());
    feCommands.append(new ReturnCommand());
    feCommands.append(new CmpCommand());
    feCommands.append(new IfCommand());
    feCommands.append(new NotifCommand());
    feCommands.append(new JumpfCommand());
    feCommands.append(new JumpbCommand());
    feCommands.append(new LoadgameCommand());
    feCommands.append(new SavegameCommand());
    feCommands.append(new AtoiCommand());
    feCommands.append(new ItoaCommand());
    feCommands.append(new SaveonCommand());
    feCommands.append(new SaveoffCommand());
    feCommands.append(new DateCommand());
    feCommands.append(new TimeCommand());
}

void NsParser::run()
{
    storageState = -2;
    storageState = -1;
    raf = new RandomAccessFile(path, "r");
    storageState = 0;
    gotoLabel("*define");
    exitFlag = false;
    argCont = false;

    while (!exitFlag) {
        exec();
    }

    QCoreApplication::quit();
}

void NsParser::error(const QString& str)
{
    qDebug() << "Error:" << str;
}

void NsParser::addHistory()
{

}

void NsParser::continueSelect()
{
    // Implementation depends on select state
}

QString NsParser::newString(const QString& str)
{
    if (str.isNull()) return QString();
    return QString(str);
}

void NsParser::setMsRest()
{
    int idx = line.indexOf(":");
    if (idx != -1) {
        lineRest = line.mid(idx + 1);
    }
}

void NsParser::textStar()
{
    // Label definition - skip
}

void NsParser::textPage()
{
    // Page break
}

void NsParser::textSd()
{
    // Self-documented text display
}

void NsParser::textW()
{
    // Wait for click with text display
}

void NsParser::textSharp()
{
    // Color change
}

void NsParser::textTilde()
{
    // Text display without wait
}

void NsParser::textShow(const QString& str)
{
    if (!str.isEmpty()) {
        putMess(str, lineCont);
    }
}

bool NsParser::settingF(const QString& line)
{
    for (SFCommand* cmd : sfCommands) {
        if (cmd->check(line)) {
            cmd->execute();
            return true;
        }
    }
    return false;
}

bool NsParser::settingFE(const QString& line)
{
    for (SFECommand* cmd : sfeCommands) {
        if (cmd->check(line)) {
            cmd->execute();
            return true;
        }
    }
    return false;
}

bool NsParser::settingE(const QString& line)
{
    for (SECommand* cmd : seCommands) {
        if (cmd->check(line)) {
            cmd->execute();
            return true;
        }
    }
    return false;
}

bool NsParser::visualE(const QString& line)
{
    for (VECommand* cmd : veCommands) {
        if (cmd->check(line)) {
            cmd->execute();
            return true;
        }
    }
    return false;
}

bool NsParser::visualFE(const QString& line)
{
    for (VFECommand* cmd : vfeCommands) {
        if (cmd->check(line)) {
            cmd->execute();
            return true;
        }
    }
    return false;
}

bool NsParser::execF(const QString& line)
{
    for (FCommand* cmd : fCommands) {
        if (cmd->check(line)) {
            cmd->execute();
            return true;
        }
    }
    return false;
}

bool NsParser::execE(const QString& line)
{
    for (ECommand* cmd : eCommands) {
        if (cmd->check(line)) {
            cmd->execute();
            return true;
        }
    }
    return false;
}

bool NsParser::execFE(const QString& line)
{
    for (FECommand* cmd : feCommands) {
        if (cmd->check(line)) {
            cmd->execute();
            return true;
        }
    }
    return false;
}

int NsParser::exec()
{
    readLine();

    if (line.isNull() || line.isEmpty()) {
        exitFlag = true;
        return storageState;
    }

    if (line.isEmpty()) return storageState;

    int i = 0;
    for (; i < line.length(); i++) {
        if (QString(" \t").indexOf(line[i]) == -1) {
            break;
        }
    }
    if (i > 0) {
        line = line.mid(i);
    }

    if (line.startsWith(";")) return storageState;
    if (line.startsWith("*")) {
        textStar();
        return storageState;
    }

    if (settingF(line)) return storageState;
    if (settingFE(line)) return storageState;
    if (settingE(line)) return storageState;
    if (visualE(line)) return storageState;
    if (visualFE(line)) return storageState;
    if (execF(line)) return storageState;
    if (execE(line)) return storageState;
    if (execFE(line)) return storageState;

    if (line.startsWith("\\")) {
        parseMessageCommand();
        textPage();
        return storageState;
    }
    if (line.startsWith("!sd")) {
        parseMessageCommand();
        textSd();
        return storageState;
    }
    if (line.startsWith("!w")) {
        parseMessageCommand();
        textW();
        return storageState;
    }
    if (line.startsWith("#")) {
        parseMessageCommand();
        textSharp();
        return storageState;
    }
    if (line.startsWith("~")) {
        parseMessageCommand();
        textTilde();
        return storageState;
    }

    QString str1 = evalStr(line);
    // Warning check
    if (!str1.isEmpty() && str1[0].unicode() < 256) {
        error("Warning: " + str1);
        return storageState;
    }

    for (i = 0; i < str1.length(); i++) {
        QChar c = str1[i];
        if (c == '_' || c == '@' || c == '%' ||
            (c >= '0' && c <= '9')) {
            str1 = str1.left(i) + str1.mid(i + 1);
            i--;
        } else if (c == '$') {
            int j = i + 1;
            for (; j < str1.length(); j++) {
                if (str1[j].unicode() >= 256) {
                    break;
                }
            }
            str1 = str1.left(i) + evalStr(str1.mid(i, j - i)) + str1.mid(j);
        } else if (c.unicode() < 256) {
            lineRest = str1.mid(i);
            str1 = str1.left(i);
            break;
        }
    }

    textShow(str1);
    return storageState;
}
